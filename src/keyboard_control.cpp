#include "Teleoperator.h"

#include <rclcpp/rclcpp.hpp>

int main(int argc, const char * argv[]) {
	rclcpp::init(argc, argv);
	turtlesim_teleop::Teleoperator teleoperator;
	return 0;
}
