//#include "Sweep.h"
//#include "EulerOps.h"
//
//#include <iostream>
//#include <vector>
//#include <cmath>
//
//static Vertex *
//findCorrespondingVertex(Vertex *original,
//                        const std::vector<Vertex *> &original_vertices,
//                        const std::vector<Vertex *> &newVertices
//) {
//    auto it = std::find(original_vertices.begin(), original_vertices.end(), original);
//}
//
///**
// * Perform a sweep operation on a 2D region with multiple inner loops.
// * @param solid: The solid to perform sweep on
// * @param direction: The direction of the sweep
// * @param distance: The distance of the sweep
// */
//void sweep(Solid *solid, const Vertex &direction, double distance) {
//    std::vector<Vertex *> original_vertices = solid->vertices;
//    std::vector<Vertex *> new_vertices;
//
//    // Step 1: Create new vertices at the sweep distance
//    for (auto &v: original_vertices) {
//        Vertex *new_v = new Vertex(v->x + direction.x * distance, v->y + direction.y * distance,
//                                   v->z + direction.z * distance);
//        new_vertices.push_back(new_v);
//        solid->vertices.push_back(new_v);
//    }
//
//    // Step 2: Create faces between old and new vertices
//    for (Edge *edge: solid->edges) {
//        Vertex *start = edge->he1->vert;
//        Vertex *end = edge->he1->next->vert;
//        Vertex *new_start =
//    }
//}
