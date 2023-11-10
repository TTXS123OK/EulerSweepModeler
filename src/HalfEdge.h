#pragma once

#include "Vertex.h"
#include "Face.h"

class HalfEdge
{
public:
    Vertex *vert; // end vertex of edge
    HalfEdge *pair; // paired half edge
    Face *face; // part of face
    HalfEdge *next; // next half edge

    HalfEdge() : vert(nullptr), pair(nullptr), face(nullptr), next(nullptr) {}
};