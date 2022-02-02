
# Setup
FROM ubuntu:21.04
RUN apt-get update -y
RUN apt-get install -y git curl zip unzip tar
RUN apt-get install -y build-essential libssl-dev
RUN apt-get install -y pkg-config
RUN apt-get install -y cmake protobuf-compiler

# Get VCPKG
RUN git clone https://github.com/Microsoft/vcpkg.git /vcpkg
RUN ./vcpkg/bootstrap-vcpkg.sh

COPY . /src
RUN rm -rf /src/build/*
RUN cmake -B /src/build -S /src -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake
