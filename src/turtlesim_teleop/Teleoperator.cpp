#include "Teleoperator.h"

turtlesim_teleop::Teleoperator::Teleoperator() {
	// Change terminal settings so that every charater is immediately sent to the program instead of allowing edits with
	// send on Enter.
	terminal_descriptor = 0;
	tcgetattr(terminal_descriptor, &original_settings);
	struct termios new_settings = original_settings;
	new_settings.c_lflag &= ~(ICANON | ECHO);
	new_settings.c_cc[VEOL] = 1;
	new_settings.c_cc[VEOF] = 2;
	tcsetattr(terminal_descriptor, TCSANOW, &new_settings);
	// Set up the ROS stuff.
	n = rclcpp::Node::make_shared("turtlesim_keyboard");
	// cmd_pub = n->crea
}

turtlesim_teleop::Teleoperator::~Teleoperator() {
	// Reset the terminal values.
	tcsetattr(terminal_descriptor, TCSANOW, &original_settings);
}