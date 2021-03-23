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
} // namespace turtlesim_teleop
