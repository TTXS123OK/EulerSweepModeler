#pragma once

#include "Vertex.h"
#include "HalfEdge.h"
#include "Edge.h"
#include "Face.h"
#include "Solid.h"

class EulerOps
{
public:
    /**
     * Make Edge and Vertex (MEV)
     * Creates a new vertex and a new edge connecting the new vertex to an existing vertex within a given face.
     * @param v: Pointer to the existing vertex
     * @param x, y, z: Coordinates of the new vertex
     * @param f: Pointer to the face within which the edge and vertex are created
     * @return: Pointer to the newly created half-edge
     */
    static HalfEdge *MEV(Vertex *v, double x, double y, double z, Face *f);

    /**
     * Make Edge and Face (MEF)
     * Creates a new edge and a new face between two vertices.
     * @param v1, v2: Pointers to the vertices between which the new edge is created
     * @param f: Pointer to the existing face which will be split
     * @return: Pointer to the newly created face
     */
    static Face *MEF(Vertex *v1, Vertex *v2, Face *f);

    /**
     * Kill Edge Make Ring (KEMR)
     * Merges two faces into one by removing an edge between them.
     * @param he: Pointer to the half-edge that represents the edge to be removed
     */
    static void KEMR(HalfEdge *he);

    /**
     * Make Vertex Face Solid (MVFS)
     * Creates a new solid with a single vertex and a single face.
     * @param x, y, z: Coordinates of the new vertex
     * @return: Pointer to the newly created solid
     */
    static Solid *MVFS(double x, double y, double z);

    /**
     * Kill Face Make Ring and Hole (KFMRH)
     * Creates a hole within a face by removing the face and creating a new face
     * with the same outer loop but with an additional inner loop.
     * @param face: Pointer to the face where the hole will be created
     * @param inner_loop: A collection of vertices or edges defining the inner loop
     * @return: Pointer to the newly created face with a loop
     */
    static Face *KFMRH(Face *face, const std::vector<Vertex *> &inner_loop);
};