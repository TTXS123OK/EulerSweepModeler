cmake_minimum_required(VERSION 3.10)
project(EulerSweepModeler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(
    EulerSweepModeler
    src/*.h
)