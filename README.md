# EulerSweepModeler

## Overview
EulerSweepModeler is a CAD course project focused on implementing a simple modeling tool using the Half-Edge data structure. This tool is designed to perform basic geometric operations based on Euler Operators and provide a sweeping mechanism for generating 3D models from 2D outlines, including those with multiple inner loops. The project also includes realistic graphic rendering of the constructed solid models.

## Project Contents
1. **Half-Edge Data Structure Implementation**: Defining and implementing a half-edge data structure to represent polygonal meshes, particularly suitable for boundary representation models.

2. **Basic Euler Operations**: Implementing five fundamental Euler operations to manipulate the half-edge data structure. These operations are essential for building and modifying the geometric models:
   - Make Edge and Vertex (MEV)
   - Make Edge and Face (MEF)
   - Kill Edge Make Ring (KEMR)
   - Make Vertex Face Solid (MVFS)
   - Kill Face Make Ring and Hole (KFMRH)

3. **Sweep Operation**: Extending the Euler operations to implement a sweeping mechanism. This feature allows the generation of 3D models by sweeping a 2D profile (with support for multiple inner loops) along a path.

4. **Realistic Graphics Rendering**: Developing a module for the realistic display of the constructed solid models. This includes implementing features like lighting, textures, and material properties for rendering the models using graphical libraries such as OpenGL.

## Course Assignment
This project is a part of the CAD course assignment, where the primary goal is to apply theoretical knowledge in computational geometry and computer-aided design to a practical modeling tool. The project emphasizes the implementation of complex geometric operations and 3D visualization techniques in C++.

## Usage
To effectively utilize the EulerSweepModeler tool, please follow the steps below. This guide assumes that you have already installed the necessary libraries on your Ubuntu 22.04 system. If not, please first install them using the command:
```shell
sudo apt-get install make cmake g++ libglfw3 libglfw3-dev libglew-dev
```

### Cloning the Repository
1. Clone the EulerSweepModeler repository from GitHub:
```shell
git clone https://github.com/TTXS123OK/EulerSweepModeler.git
```
2. Navigate to the EulerSweepModeler directory:
```shell
cd EulerSweepModeler
```

### Building the Project
1. Create a build directory and navigate into it:
```shell
mkdir build
cd build
```
2. Generate the makefile using CMake:
```shell
cmake ..
```
3. Compile the project:
```shell
make
```

### Running the Tests and Renderer
1. To run the Euler operations test, execute:
```shell
./EulerOpsTest
```
This will perform a series of tests to ensure that the basic Euler operations are functioning correctly.
2. To start the realistic graphics renderer, run:
```shell
./Render
```
This will launch the rendering module, displaying the constructed solid models with the implemented graphical features.

