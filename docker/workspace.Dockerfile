# This creates the image that the project source code will be developed in.
# You can target any ROS distro, but the latest at the time of project creation (Foxy) is the default.
ARG ROS_DISTRO=foxy
FROM ros:${ROS_DISTRO}
RUN apt update && \
	apt install -y ros-${ROS_DISTRO}-turtlesim && \
	rm -rf /var/lib/apt/lists/*
# Set environmental variables assuming this is run in a container on Windows, so it needs X11 forwarding.
ENV DISPLAY=host.docker.internal:0.0
ENV LIBGL_ALWAYS_INDIRECT=1
CMD [ "bash" ]