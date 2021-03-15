# Builds a development environment for creating the package.
ARG ROS_DISTRO=foxy
FROM ros:${ROS_DISTRO}
# Set environmental variables assuming this is run in a container on Windows, so it needs X11 forwarding.
ENV DISPLAY=host.docker.internal:0.0
ENV LIBGL_ALWAYS_INDIRECT=1
CMD [ "bash" ]