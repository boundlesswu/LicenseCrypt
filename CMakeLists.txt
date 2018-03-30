cmake_minimum_required(VERSION 3.7)
project(TestAESCipher)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES LicenseInfo.h AES.cpp main.cpp)
add_executable(TestAESCipher ${SOURCE_FILES})