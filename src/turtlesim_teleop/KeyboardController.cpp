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
			try {
				read(terminal_descriptor, &c, 1);
				switch (c) {
					case 'a':
					case 'A':
						std::cout << "Left" << std::endl;
						break;
					case 'w':
					case 'W':
						std::cout << "Forward" << std::endl;
						break;
					case 'd':
					case 'D':
						std::cout << "Right" << std::endl;
						break;
					case 's':
					case 'S':
						std::cout << "Backward" << std::endl;
						break;
					case 0:
						rclcpp::shutdown();
						break;
					default:
						break;
				}
			} catch (const std::exception & e) {
				RCLCPP_FATAL(this->get_logger(), "Error reading keyboard commands: '%s'", e.what());
			}
		}
	}
} // namespace turtlesim_teleop
