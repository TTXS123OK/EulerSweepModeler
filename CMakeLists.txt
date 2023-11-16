cmake_minimum_required(VERSION 3.10)
project(EulerSweepModeler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(
        ${PROJECT_SOURCE_DIR}/src
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIRS}
        ${GLFW_INCLUDE_DIRS}
)

add_executable(
        EulerSweepModeler
        src/EulerOps.cpp
        src/EulerOpsTest.cpp
)

# Prefer to use GLVND
if (NOT DEFINED OpenGL_GL_PREFERENCE)
    set(OpenGL_GL_PREFERENCE "GLVND")
endif ()

add_executable(
        Render
        src/EulerOps.cpp
        src/Sweep.cpp
        src/Render.cpp
)


target_link_libraries(
        Render
        OpenGL::GL
        GLEW::GLEW
        glfw
)
