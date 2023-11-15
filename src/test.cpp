#include "EulerOps.h"
#include <iostream>

void printFace(Face* face) {
    HalfEdge* start = face->edge;
    HalfEdge* current = start;

    do {
        std::cout << "Vertex: (" << current->vert->x << ", " << current->vert->y << ", " << current->vert->z << ")\n";
        current = current->next;
    } while (current != start);
}

int main() {
    // create a triangle face
    Vertex* v1 = new Vertex(0, 0, 0);
    Vertex* v2 = new Vertex(1, 0, 0);
    Vertex* v3 = new Vertex(0, 1, 0);

    HalfEdge* he1 = new HalfEdge();
    HalfEdge* he2 = new HalfEdge();
    HalfEdge* he3 = new HalfEdge();

    std::cout << "created 3 vertices and 6 halfedges" << std::endl;

    he1->vert = v1; he2->vert = v2; he3->vert = v3;
    he1->next = he2; he2->next = he3; he3->next = he1;

    Face* f = new Face();
    f->edge = he1;
    he1->face = he2->face = he3->face = f;

    v1->edge = he1; v2->edge = he2; v3->edge = he3;

    // apply MEV operation
    HalfEdge* newHE = EulerOps::MEV(v1, 0.5, 0.5, 0, f);

    // apply MEF operation
    Face* newF = EulerOps::MEF(v1, newHE->vert, f);

    // print vertices of origin face and the new face
    std::cout << "Original Face:\n";
    printFace(f);

    std::cout << "New Face:\n";
    printFace(newF);

    return 0;
}
