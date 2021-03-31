#include "KeyboardController.h"

namespace turtlesim_teleop {
	KeyboardController::KeyboardController() :
			Node("keyboard_controller") {
		// Store the old terminal parameters and set the configuration to the right setup.
		terminal_descriptor = 0;
		tcgetattr(terminal_descriptor, &terminal_original_parameters);
		termios terminal_new_parameters = terminal_original_parameters;
		terminal_new_parameters.c_lflag &= ~(ICANON | ECHO);
		terminal_new_parameters.c_cc[VEOL] = 1;
		terminal_new_parameters.c_cc[VEOF] = 2;
		tcsetattr(terminal_descriptor, TCSANOW, &terminal_new_parameters);
		// Set up the publisher.
		publisher = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 1);
	}
	KeyboardController::~KeyboardController() {
		// Restore the terminal settings.
		tcsetattr(terminal_descriptor, TCSANOW, &terminal_original_parameters);
	}
	void KeyboardController::readKeyboard() {
		while (rclcpp::ok()) {
			// Right now, just look for ASWD. This returns values for most keys, but the others are not so easily
			// mapped. However 0 represents the Ctrl-C command. (Use printf("%02", c) to see.)
			char c = 0;
			geometry_msgs::msg::Twist msg;
			try {
				read(terminal_descriptor, &c, 1);
				switch (c) {
					case 'a':
					case 'A':
						RCLCPP_DEBUG(this->get_logger(), "Heard: Left");
						msg.linear.x = 0.0;
						msg.linear.y = 1.0;
						msg.angular.z = 0.0;
						break;
					case 'w':
					case 'W':
						RCLCPP_DEBUG(this->get_logger(), "Heard: Forward");
						msg.linear.x = 1.0;
						msg.linear.y = 0.0;
						msg.angular.z = 0.0;
						break;
					case 'd':
					case 'D':
						RCLCPP_DEBUG(this->get_logger(), "Heard: Right");
						msg.linear.x = 0.0;
						msg.linear.y = -1.0;
						msg.angular.z = 0.0;
						break;
					case 's':
					case 'S':
						RCLCPP_DEBUG(this->get_logger(), "Heard: Backward");
						msg.linear.x = -1.0;
						msg.linear.y = 0.0;
						msg.angular.z = 0.0;
						break;
					case 0:
						RCLCPP_DEBUG(this->get_logger(), "Shutting down");
						rclcpp::shutdown();
						break;
					default:
						break;
				}
			} catch (const std::exception & e) {
				RCLCPP_FATAL(this->get_logger(), "Error reading keyboard commands: '%s'", e.what());
			}
			publisher->publish(msg);
		}
	}
} // namespace turtlesim_teleop
