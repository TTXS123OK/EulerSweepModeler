#include "EulerOps.h"
#include <iostream>

void printFace(Face *face);

void test_MEV_MEF();

void test_KEMR_MVFS();

int main() {
    test_KEMR_MVFS();
    return 0;
}

void printFace(Face *face) {
    HalfEdge *start = face->edge;
    HalfEdge *current = start;

    do {
        std::cout << "Vertex: (" << current->vert->x << ", " << current->vert->y << ", " << current->vert->z << ")\n";
        current = current->next;
    } while (current != start);
}

void test_MEV_MEF() {
    // create a triangle face
    Vertex *v1 = new Vertex(0, 0, 0);
    Vertex *v2 = new Vertex(1, 0, 0);
    Vertex *v3 = new Vertex(0, 1, 0);

    HalfEdge *he1 = new HalfEdge();
    HalfEdge *he2 = new HalfEdge();
    HalfEdge *he3 = new HalfEdge();

    std::cout << "created 3 vertices and 3 half-edges" << std::endl;

    he1->vert = v1;
    he2->vert = v2;
    he3->vert = v3;
    he1->next = he2;
    he2->next = he3;
    he3->next = he1;

    Face *f = new Face();
    f->edge = he1;
    he1->face = he2->face = he3->face = f;

    v1->edge = he1;
    v2->edge = he2;
    v3->edge = he3;

    // apply MEV operation
    HalfEdge *newHE = EulerOps::MEV(v1, 0.5, 0.5, 0, f);

    // apply MEF operation
    Face *newF = EulerOps::MEF(v1, newHE->vert, f);

    // print vertices of origin face and the new face
    std::cout << "Original Face:\n";
    printFace(f);

    std::cout << "New Face:\n";
    printFace(newF);
}

void test_KEMR_MVFS() {
    // use MVFS to create an initial face and solid
    Solid *solid = EulerOps::MVFS(0, 0, 0);
    Face *f = solid->faces.front();
    Vertex *v1 = solid->vertices.front();

    // use MEV and MEF to create more vertices and edges to form a quadrilateral
    HalfEdge *he1 = EulerOps::MEV(v1, 1, 0, 0, f);
    Vertex *v2 = he1->vert;
    HalfEdge *he2 = EulerOps::MEV(v2, 1, 1, 0, f);
    Vertex *v3 = he2->vert;
    HalfEdge *he3 = EulerOps::MEV(v3, 0, 1, 0, f);
    Vertex *v4 = he3->vert;
    Face *f2 = EulerOps::MEF(v4, v1, f);

    // apply KEMR
    EulerOps::KEMR(he3);

    // validate KEMR
    HalfEdge *start = f->edge;
    HalfEdge *current = start;

    bool is_edge_removed = true;
    do {
        if (current->face != f) {
            std::cout << "Error: Not all half-edges are assigned to the same face" << std::endl;
            is_edge_removed = false;
            break;
        }

        if (current == he3 || current == he3->pair) {
            std::cout << "Error: The removed edge is still part of the face" << std::endl;
            is_edge_removed = false;
            break;
        }

        current = current->next;
    } while (current != start && current != nullptr);

    if (is_edge_removed) {
        std::cout << "KEMR operation successful: Edge removed and faces merged" << std::endl;
    } else {
        std::cout << "KEMR operation failed" << std::endl;
    }
}