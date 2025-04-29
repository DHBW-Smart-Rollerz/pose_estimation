#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/int16.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "peInterface/PoseEstimator.h"

// https://docs.ros.org/en/jazzy/Tutorials/Beginner-Client-Libraries/Writing-A-Simple-Cpp-Publisher-And-Subscriber.html
// Within the node, handlers for dynamic bicycle model and EKF could be used
// MATLAB Models for EKF, DMB -> Generated C++ Classes -> Ros2 Node

class PoseEstimationNode : public rclcpp::Node
{
public:
    PoseEstimationNode() : Node("pose_estimation_node")
    {
        this->declare_parameter("sub_imu_topic", "/sensor/imu");
        this->declare_parameter("sub_velocity_topic", "/sensor/velocity");
        this->declare_parameter("sub_steering_angle_topic", "/control/steering_angle/target");
        this->declare_parameter("pub_pose_topic", "/pose_estimation/pose");
        this->declare_parameter("pub_ekf_state_topic", "/pose_estimation/velocity");
        this->declare_parameter("estimation_interval_milliseconds", 5);

        std::string sub_imu_topic = this->get_parameter("sub_imu_topic").as_string();
        std::string sub_velocity_topic = this->get_parameter("sub_velocity_topic").as_string();
        std::string sub_steering_angle_topic = this->get_parameter("sub_steering_angle_topic").as_string();
        std::string pub_pose_topic = this->get_parameter("pub_pose_topic").as_string();
        std::string pub_ekf_state_topic = this->get_parameter("pub_ekf_state_topic").as_string();
        int estimation_interval_milliseconds = this->get_parameter("estimation_interval_milliseconds").as_int();

        pose_publisher_ = this->create_publisher<geometry_msgs::msg::Pose>(pub_pose_topic, 1);
        state_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(pub_ekf_state_topic, 1);

        auto imu_callback_ = [this](sensor_msgs::msg::Imu::UniquePtr msg) {
            this->imu_gyro = msg->angular_velocity.z;
            this->imu_acc = msg->linear_acceleration.x;
            RCLCPP_INFO(this->get_logger(), "I heard: gyro: '%lf', acceleration: '%lf",
                        this->imu_gyro, this->imu_acc);

        };

        auto velocity_callback = [this](std_msgs::msg::Float32::UniquePtr msg) {
            this->sensor_velocity = msg->data;
            RCLCPP_INFO(this->get_logger(), "I heard: velocity: '%f'", this->sensor_velocity);

        };

        auto steering_angle_callback = [this](std_msgs::msg::Int16::UniquePtr msg) {
            this->steering_angle = (double) msg->data; // TODO: Umrechnen
            RCLCPP_INFO(this->get_logger(), "I heard: steering angle: '%lf'", this->steering_angle);

        };


        imu_subscription_ = this->create_subscription<sensor_msgs::msg::Imu>(
            sub_imu_topic, 1, imu_callback_);

        velocity_subscription_ = this->create_subscription<std_msgs::msg::Float32>(
            sub_velocity_topic, 1, velocity_callback);

        control_angle_subscription_ = this->create_subscription<std_msgs::msg::Int16>(
            sub_steering_angle_topic, 1, steering_angle_callback);        

        double dt = (double)estimation_interval_milliseconds;
        dt = dt / 1000;
        const double parameters[6] = {-20.0, -60.0, 0.175, 0.085, 0.0283384, 2.985}; // c_f, c_r, l_f, l_r, J, m
        const double processNoise[9] = {1e-3, 0, 0, 0, 1e-6, 0, 0, 0, 1e-3}; // v_x, v_y, psi_dot
        const double measurementNoise[4] = {1.0, 0, 0, 1.0}; 
        poseEstimator.init(parameters, dt, processNoise, measurementNoise);


        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(estimation_interval_milliseconds), 
            std::bind(&PoseEstimationNode::timer_callback, this)
            );
    }

private:

    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_subscription_;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr velocity_subscription_;
    rclcpp::Subscription<std_msgs::msg::Int16>::SharedPtr control_angle_subscription_;


    rclcpp::Publisher<geometry_msgs::msg::Pose>::SharedPtr pose_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr state_publisher_;




    float sensor_velocity = 0.0;
    double imu_acc = 0.0;
    double imu_gyro = 0.0;
    double steering_angle = 0.0; // = 0.0598 x -267.97

    PoseEstimator poseEstimator;


    void timer_callback()
    {
        RCLCPP_INFO(this->get_logger(), "Timer called!");

        double u[2] = {this->steering_angle, this->imu_acc}; // delta, acc_y
        double z[2] = {this->imu_gyro, this->sensor_velocity};   // gyro_z, v_x
        double pose_result[3];
        double state_result[3];

        poseEstimator.predict(u);
        poseEstimator.correct(z);
        poseEstimator.getState(pose_result);
        poseEstimator.getPose(state_result);

        geometry_msgs::msg::Pose pose_msg;
        geometry_msgs::msg::Twist velocity_msg;

        pose_msg.position.x = pose_result[0];
        pose_msg.position.y = pose_result[1];
        pose_msg.position.z = 0.0;
        pose_msg.orientation.w = 0.0;
        pose_msg.orientation.x = 0.0;
        pose_msg.orientation.y = 0.0;
        pose_msg.orientation.z = pose_result[2];  // radians

        velocity_msg.angular.x = 0.0;
        velocity_msg.angular.y = 0.0;
        velocity_msg.angular.z = state_result[2];
        velocity_msg.linear.x = state_result[0];
        velocity_msg.linear.y = state_result[1];
        velocity_msg.linear.z = 0;

        this->pose_publisher_->publish(pose_msg);
        this->state_publisher_->publish(velocity_msg);
    }
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PoseEstimationNode>());
    rclcpp::shutdown();
    return 0;
}
