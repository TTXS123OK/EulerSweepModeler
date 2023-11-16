#pragma once

#include "HalfEdge.h"

class HalfEdge; // forward declaration

class Face {
public:
    HalfEdge *edge; // part of this face

    Face() : edge(nullptr) {}
};