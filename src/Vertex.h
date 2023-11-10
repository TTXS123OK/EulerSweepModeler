#pragma once

#include "HalfEdge.h"

class Vertex
{
public:
    double x, y, z; // coordinates of the vertex
    HalfEdge *edge; // starting point of a half edge

    Vertex(double x, double y, double z) : x(x), y(y), z(z), edge(nullptr) {}
};