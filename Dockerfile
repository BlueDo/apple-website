
# Setup
FROM ubuntu:21.04 as build
RUN apt-get update -y
RUN apt-get install -y git curl zip unzip tar
RUN apt-get install -y build-essential libssl-dev
RUN apt-get install -y pkg-config
RUN apt-get install -y cmake protobuf-compiler

# Get VCPKG
RUN git clone https://github.com/Microsoft/vcpkg.git /vcpkg
RUN ./vcpkg/bootstrap-vcpkg.sh

COPY . .
RUN rm -rf /build/*
RUN cmake -B /build -S . -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake
RUN make -C build
CMD ["./build/Apple.out"]

FROM ubuntu:21.04 as prod
COPY --from=build /build/Apple.out .
CMD ["./Apple.out"]
