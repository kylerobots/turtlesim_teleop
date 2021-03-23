#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include "rclcpp/rclcpp.hpp"

#include <termios.h>

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

		private:
		/**
		 * @brief The index ID referencing the terminal.
		 * 
		 */
		int terminal_descriptor;

		/**
		 * @brief The struct to hold the terminal's parameters before starting the node.
		 * 
		 * These are used to restore the terminal to the way it was before when the node exits.
		 */
		termios terminal_original_parameters;
	};

} // namespace turtlesim_teleop

#endif // KEYBOARD_CONTROLLER_H