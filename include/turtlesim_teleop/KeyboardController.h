#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"

#include <termios.h>
#include <unistd.h>

namespace turtlesim_teleop {
	/**
	 * @brief This class reads keyboard input and converts it to velocity commands.
	 * 
	 * This inherits from ROS2's node class and provides the publisher needed to control velocity. Upon construction,
	 * it will modify terminal settings to allow a continuous read of key presses. These are read as characters and
	 * converted into the appropriate Twist commands.
	 */
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

		/**
		 * @brief Continually checks for keyboard input and sends the appropriate command in response.
		 * 
		 * This function runs in a continuous loop as long as ROS is active. At each loop, it attempts to read 1
		 * character from the command line. This character can then be used for control of the turtlebot. This was done
		 * as a real quick way to get keyboard parsing working. Because it reads single characters at a time, it has
		 * undefined behavior for things like arrow keys. It also specifically watches for a Ctrl-C kill command and
		 * manually initiates shutdown when detected. Again, this is just to get something working very quick and is
		 * probably not the best way to do it.
		 */
		void readKeyboard();

		private:
		/**
		 * @brief The cmd_vel publisher.
		 * 
		 */
		rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher;

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