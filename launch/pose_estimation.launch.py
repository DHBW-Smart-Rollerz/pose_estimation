from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.parameter_descriptions import ParameterFile
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    # Declare the path to the config file as a launch argument
    # Get the share directory of the package
    package_share_directory = get_package_share_directory("pose_estimation")

    # Construct the path to the configuration file
    config_file_path = os.path.join(
        package_share_directory, "config", "ros_params.yaml"
    )

    # Declare the path to the config file as a launch argument
    config_file_arg = DeclareLaunchArgument(
        "config_file",
        default_value=config_file_path,
        description="Path to the configuration file for pose_estimation_node",
    )

    # Load the configuration file
    config_file = LaunchConfiguration("config_file")

    # Define the pose_estimation_node
    pose_estimation_node = Node(
        package="pose_estimation",
        executable="pose_estimation_node",
        name="pose_estimation_node",
        output="screen",
        parameters=[ParameterFile(config_file, allow_substs=True)],
    )

    return LaunchDescription([config_file_arg, pose_estimation_node])
