#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float32.hpp"
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
        this->declare_parameter("pub_pose_topic", "/pose_estimation/pose");
        this->declare_parameter("pub_ekf_state_topic", "/pose_estimation/velocity");
        this->declare_parameter("estimation_interval_milliseconds", 5);

        std::string sub_imu_topic = this->get_parameter("sub_imu_topic").as_string();
        std::string sub_velocity_topic = this->get_parameter("sub_velocity_topic").as_string();
        std::string pub_pose_topic = this->get_parameter("pub_pose_topic").as_string();
        std::string pub_ekf_state_topic = this->get_parameter("pub_ekf_state_topic").as_string();
        int estimation_interval_milliseconds = this->get_parameter("estimation_interval_milliseconds").as_int();

        pose_publisher_ = this->create_publisher<geometry_msgs::msg::Pose>(pub_pose_topic, 1);
        state_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(pub_ekf_state_topic, 1);



        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(estimation_interval_milliseconds), 
            std::bind(&PoseEstimationNode::timer_callback, this)
            );

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


        imu_subscription_ = this->create_subscription<sensor_msgs::msg::Imu>(
            sub_imu_topic, 1, imu_callback_);

        velocity_subscription_ = this->create_subscription<std_msgs::msg::Float32>(
            sub_velocity_topic, 1, velocity_callback);
    }

private:

    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_subscription_;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr velocity_subscription_;

    rclcpp::Publisher<geometry_msgs::msg::Pose>::SharedPtr pose_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr state_publisher_;


    void timer_callback()
    {


        RCLCPP_INFO(this->get_logger(), "Timer called!");
    }
    rclcpp::TimerBase::SharedPtr timer_;

    float sensor_velocity = 0.0;
    double imu_acc = 0.0;
    double imu_gyro = 0.0;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PoseEstimationNode>());
    rclcpp::shutdown();
    return 0;
}
