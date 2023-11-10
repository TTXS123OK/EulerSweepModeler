#pragma once

#include "HalfEdge.h"

class Edge
{
public:
    HalfEdge *he1;
    HalfEdge *he2;

    Edge() : he1(nullptr), he2(nullptr) {}
};