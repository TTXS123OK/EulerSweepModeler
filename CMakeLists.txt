cmake_minimum_required(VERSION 3.10)
project(EulerSweepModeler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(
    EulerSweepModeler
    src/EulerOps.cpp
    src/Sweep.cpp
    src/EulerOpsTest.cpp)
