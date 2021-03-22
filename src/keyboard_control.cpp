#include "KeyboardController.h"
#include "rclcpp/rclcpp.hpp"

int main(int argc, const char ** argv) {
	rclcpp::init(argc, argv);
	turtlesim_teleop::KeyboardController controller;
	return 0;
}
