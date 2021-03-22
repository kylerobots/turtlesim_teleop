#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include "rclcpp/rclcpp.hpp"

namespace turtlesim_teleop {
	class KeyboardController : public rclcpp::Node {
		public:
		/**
		 * @brief Construct a new Keyboard Controller object.
		 * 
		 * This starts up the ROS node and puts the terminal in the right mode to read data instantly from the
		 * keyboard.
		 */
		KeyboardController();
		/**
		 * @brief Destroy the Keyboard Controller object.
		 * 
		 * This also returns the terminal settings to the way they were before the node started.
		 * 
		 */
		~KeyboardController();
	};

} // namespace turtlesim_teleop

#endif // KEYBOARD_CONTROLLER_H