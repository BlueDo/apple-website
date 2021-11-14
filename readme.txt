
Pre-requisites
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install pkg-config



Command to build libraries
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=[pathtovcpkg]/scripts/buildsystems/vcpkg.cmake
