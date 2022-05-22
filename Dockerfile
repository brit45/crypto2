# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM ubuntu:21.10

# These commands copy your files into the specified directory in the image
# and set that as the working location
COPY . /src
WORKDIR /src

ENV DEBIAN_FRONTEND=noninteractive \
    TZ=Europe/PARIS


RUN apt-get update && \
    apt-get -y dist-upgrade && \
    apt-get install -y git cmake make libcrypto++-dev libcrypto++-utils libjsoncpp-dev g++ pkg-config

WORKDIR /src

RUN cmake . && make

# This command runs your application, comment out this line to compile only
CMD ./cryptos

LABEL Name=crypto2 Version=0.0.1