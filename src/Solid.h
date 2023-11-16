#pragma once

#include "Face.h"
#include "Vertex.h"
#include <vector>

class Solid {
public:
    std::vector<Face *> faces;      // A list of faces in the solid
    std::vector<Vertex *> vertices; // A list of vertices in the solid
};