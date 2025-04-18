FROM debian:buster AS aasdk

RUN dpkg --add-architecture armhf
RUN apt-get update
RUN apt-get -y install cmake build-essential git
RUN apt-get -y install gcc-arm-linux-gnueabihf cpp-arm-linux-gnueabihf g++-arm-linux-gnueabihf protobuf-compiler
RUN apt-get -y install gcc-8-base:armhf libc6:armhf libgcc1:armhf libicu63:armhf libidn2-0:armhf libstdc++6:armhf libunistring2:armhf

# These are all the libboost requirements. It would be shorter if libboost-log-dev wasn't a disaster that's being dealt with manually.
RUN apt-get install -y libprotobuf-dev libusb-1.0.0-dev libssl-dev libboost-dev libboost-system-dev libboost-atomic1.67.0 libboost-chrono1.67.0 libboost-date-time1.67.0 libboost-filesystem1.67.0 libboost-regex1.67.0 libboost-thread1.67.0 libboost-filesystem1.67-dev libboost-thread1.67-dev libboost-date-time1.67-dev
RUN apt-get install -y libprotobuf-dev:armhf libusb-1.0.0-dev:armhf libssl-dev:armhf libboost-dev:armhf libboost-system-dev:armhf libboost-atomic1.67.0:armhf libboost-chrono1.67.0:armhf libboost-date-time1.67.0:armhf libboost-filesystem1.67.0:armhf libboost-regex1.67.0:armhf libboost-system1.67.0:armhf libboost-thread1.67.0:armhf libboost-filesystem1.67-dev:armhf libboost-thread1.67-dev:armhf libboost-date-time1.67-dev:armhf

COPY / /src

WORKDIR /src

# Import resources
COPY ./buildenv/patch-libboost-log-deb.sh /src/resources/patch-libboost-log-deb.sh
COPY ./buildenv/entrypoint.sh /entrypoint.sh

# Patch libboost-log-dev and install
RUN chmod +x ./resources/patch-libboost-log-deb.sh
RUN ./resources/patch-libboost-log-deb.sh

# Make Executable
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/bin/bash", "/entrypoint.sh"]