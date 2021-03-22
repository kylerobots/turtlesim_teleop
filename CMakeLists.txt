cmake_minimum_required(VERSION 3.5)
project(turtlesim_teleop)

# Default to C99
if(NOT CMAKE_C_STANDARD)
	set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(keyboard_control
	src/keyboard_control.cpp
	src/turtlesim_teleop/KeyboardController.cpp
)
target_include_directories(keyboard_control
	PRIVATE
		include/turtlesim_teleop
)
ament_target_dependencies(keyboard_control
	rclcpp
)

install(TARGETS keyboard_control
	DESTINATION lib/${PROJECT_NAME}
)

ament_package()
