#ifndef TURTLESIM_TELEOP_TELEOPERATOR
#define TURTLESIM_TELEOP_TELEOPERATOR

#include <geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>
#include <termios.h>

namespace turtlesim_teleop {

	/**
 	 * @brief A class to read keyboard inputs and convert into velocity commands.
 	 */
	class Teleoperator {
		public:
		/**
		 * @brief The default constructor.
		 * */
		Teleoperator();
		/**
		 * @brief The default destructor.
		 * 
		 * This also restores all terminal settings to their original values.
		 */
		~Teleoperator();

		private:
		/**
		 * @brief The publisher for the command velocity.
		 * 
		 */
		rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_pub;

		/**
		 * @brief The ROS node handle.
		 * 
		 */
		rclcpp::Node::SharedPtr n;

		/**
		 * @brief A struct to hold original terminal settings to allow reset when the node finishes.
		 * 
		 */
		struct termios original_settings;

		/**
	 	 * @brief The terminal to capture data from.
	 	 * 
		 * This will always be 0 for now.
		 */
		int terminal_descriptor;
	};
} // namespace turtlesim_teleop
#endif
