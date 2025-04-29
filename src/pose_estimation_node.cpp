#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "peInterface/PoseEstimator.h"

// https://docs.ros.org/en/jazzy/Tutorials/Beginner-Client-Libraries/Writing-A-Simple-Cpp-Publisher-And-Subscriber.html
// Within the node, handlers for dynamic bicycle model and EKF could be used
// MATLAB Models for EKF, DMB -> Generated C++ Classes -> Ros2 Node

class MiddleMan : public rclcpp::Node
{
public:
    MiddleMan() : Node("middle_man"), count_(0)
    {
        // Publisher for "secondTopic"
        publisher_ = this->create_publisher<std_msgs::msg::String>("secondTopic", 10);

        // Sender callback to publish the message
        sender_callback_ = [this](const std::string &data) {
            auto message = std_msgs::msg::String();
            message.data = "Forwarded: " + data + " (count: " + std::to_string(this->count_++) + ")";
            RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
            this->publisher_->publish(message);
        };

        // Callback for when a message is received on "firstTopic"
        auto topic_callback = [this](std_msgs::msg::String::UniquePtr msg) {
            RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
            sender_callback_(msg->data); // Use the member variable callback
        };

        // Subscription to "firstTopic"
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "firstTopic", 10, topic_callback);
    }

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    std::function<void(const std::string &)> sender_callback_; // Use std::function for callback
    size_t count_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MiddleMan>());
    rclcpp::shutdown();
    return 0;
}
