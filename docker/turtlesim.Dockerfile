# This Dockerfile starts up a ROS2 instance of the actual turtlesim display GUI. It is not for control, debug, or
# anything else. You can target any ROS distro, but the latest at the time of project creation (Foxy) is the default.
ARG ROS_DISTRO=foxy
# Use the minimal version to keep the image size down. Since this is just the simulation, nothing much is needed.
FROM ros:${ROS_DISTRO}-ros-core
RUN apt update && \
	apt install -y ros-${ROS_DISTRO}-turtlesim && \
	rm -rf /var/lib/apt/lists/*
# Set environmental variables assuming this is run in a container on Windows, so it needs X11 forwarding.
ENV DISPLAY=host.docker.internal:0.0
ENV LIBGL_ALWAYS_INDIRECT=1
CMD [ "ros2", "run", "turtlesim", "turtlesim_node" ]