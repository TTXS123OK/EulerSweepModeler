#pragma once

#include "HalfEdge.h"

class Face
{
public:
    HalfEdge *edge; // part of this face

    Face() : edge(nullptr) {}
};