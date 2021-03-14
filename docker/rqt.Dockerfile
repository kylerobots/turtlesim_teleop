# This creates an image containing RQT and other debugging/introspection tools.
# Any version of ROS can be used, but default is the latest at time of package creation (Foxy).
ARG ROS_DISTRO=foxy
FROM ros:${ROS_DISTRO}-ros-base
# Turtlesim is needed for message definitions. Install all the rqt plugins to provide maximum flexibility.
RUN apt update && \
	apt install -y \
	ros-${ROS_DISTRO}-turtlesim \
	ros-${ROS_DISTRO}-rqt*
# Set environmental variables assuming this is run in a container on Windows, so it needs X11 forwarding.
ENV DISPLAY=host.docker.internal:0.0
ENV LIBGL_ALWAYS_INDIRECT=1
CMD [ "rqt" ]