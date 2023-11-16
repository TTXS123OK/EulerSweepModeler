#include "Sweep.h"
#include "EulerOps.h"

#include <iostream>
#include <vector>
#include <cmath>

/**
 * Perform a sweep operation on a 2D region with multiple inner loops.
 * @param solid: The solid to perform sweep on
 * @param direction: The direction of the sweep
 * @param distance: The distance of the sweep
 */
void sweep(Solid *solid, const Vertex &direction, double distance) {
    std::vector<Vertex*> original_vertices = solid->vertices;
    std::vector<Vertex*> new_vertices;

    for (auto v : original_vertices) {
        Vertex *new_v = new Vertex(v->x + direction.x * distance, v->y + direction.y * distance, v->z + direction.z * distance);
        new_vertices.push_back(new_v);
        solid->vertices.push_back(new_v);
    }

    for (int i = 0; i < original_vertices.size(); i++) {
        Vertex *start = original_vertices[i];
        Vertex *end = new_vertices[i];

        EulerOps::MEV(start, end->x, end->y, end->z, solid->faces.front());
    }

    for (int i=0; i<new_vertices.size()-1; i++) {
        auto new_f = EulerOps::MEF(new_vertices[i], new_vertices[i+1], solid->faces.front());
        solid->faces.push_back(new_f);
    }
}