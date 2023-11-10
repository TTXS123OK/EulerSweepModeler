#pragma once

#include "HalfEdge.h"

class Vertex
{
public:
    float x, y, z; // coordinates of the vertex
    HalfEdge *edge; // starting point of a half edge

    Vertex(float x, float y, float z) : x(x), y(y), z(z), edge(nullptr) {}
};