# turtlesim_teleop #
A practice ROS2 package to control the turtlesim robot. This provides a simple keyboard teleoperation node. The real
goal of the project is to practice developing in ROS2, using containers, and performing various code quality steps.

## Prerequisites ##
This README assumes you are working in Docker containers on Windows. It also assumes VS Code as the IDE of choice,
although this is less impactful on the steps. If running on Ubuntu natively, the correct ROS commands can be easily run.

You should have Docker and some sort of X11 server (such as VcXserv) installed. They should both be started up.

## Starting the Simulation ##
The *compose.yaml* file in the *docker* subfolder is used to start the environment. Run ```docker compose up``` to build
the containers and start the right nodes. If successful, you should see the familiar turtlesim GUI window appear. An rqt
windows should also appear for any introspection that may be required.
