#include "EulerOps.h"
#include <iostream>

void printFace(Face *face);

int main() {
    // Use MFVS to first create a solid
    Solid *solid = EulerOps::MVFS(0, 0, 0);
    Vertex *v1 = solid->vertices.front();
    Face *f_tmp = solid->faces.front();

    // Use 3 MEV and 1 MEF to create a square
    HalfEdge *he1 = EulerOps::MEV(v1, 3, 0, 0, f_tmp);
    HalfEdge *he1_ = he1->pair;
    Vertex *v2 = he1->vert;
    HalfEdge *he2 = EulerOps::MEV(v2, 3, 3, 0, f_tmp);
    HalfEdge *he2_ = he2->pair;
    Vertex *v3 = he2->vert;
    HalfEdge *he3 = EulerOps::MEV(v3, 0, 3, 0, f_tmp);
    HalfEdge *he3_ = he3->pair;
    Vertex *v4 = he3->vert;
    Face *f1 = EulerOps::MEF(v1, v4, f_tmp);
    HalfEdge *he4 = he3->next;
    HalfEdge *he4_ = he4->pair;

    // Use 4 MEV to create 4 columns
    HalfEdge *he5 = EulerOps::MEV(v1, 0, 0, 3, f_tmp);
    HalfEdge *he5_ = he5->pair;
    Vertex *v5 = he5->vert;
    HalfEdge *he6 = EulerOps::MEV(v2, 3, 0, 3, f_tmp);
    HalfEdge *he6_ = he6->pair;
    Vertex *v6 = he6->vert;
    HalfEdge *he7 = EulerOps::MEV(v3, 3, 3, 3, f_tmp);
    HalfEdge *he7_ = he7->pair;
    Vertex *v7 = he7->vert;
    HalfEdge *he8 = EulerOps::MEV(v4, 0, 3, 3, f_tmp);
    HalfEdge *he8_ = he8->pair;
    Vertex *v8 = he8->vert;

    // Use 4 MEF to create 4 new faces
    Face *f2 = EulerOps::MEF(v5, v6, f_tmp);
    HalfEdge *he9 = he5->next;
    HalfEdge *he9_ = he9->pair;
    Face *f3 = EulerOps::MEF(v6, v7, f_tmp);
    HalfEdge *he10 = he6->next;
    HalfEdge *he10_ = he10->pair;
    Face *f4 = EulerOps::MEF(v7, v8, f_tmp);
    HalfEdge *he11 = he7->next;
    HalfEdge *he11_ = he11->pair;
    Face *f5 = EulerOps::MEF(v8, v5, f_tmp);
    HalfEdge *he12 = he8->next;
    HalfEdge *he12_ = he12->pair;

    // Use 4 MEV and 1 MEF to create the first loop in the top face
    HalfEdge *he_tmp = EulerOps::MEV(v5, 1, 1, 3, f_tmp);
    HalfEdge *he_tmp_ = he_tmp->pair;
    Vertex *v9 = he_tmp->vert;
    HalfEdge *he13 = EulerOps::MEV(v9, 2, 1, 3, f_tmp);
    HalfEdge *he13_ = he13->pair;
    Vertex *v10 = he13->vert;
    HalfEdge *he14 = EulerOps::MEV(v10, 2, 2, 3, f_tmp);
    HalfEdge *he14_ = he14->pair;
    Vertex *v11 = he14->vert;
    HalfEdge *he15 = EulerOps::MEV(v11, 1, 2, 3, f_tmp);
    HalfEdge *he15_ = he15->pair;
    Vertex *v12 = he15->vert;
    Face *f6 = EulerOps::MEF(v9, v12, f_tmp);
    HalfEdge *he16 = he15->next;
    HalfEdge *he16_ = he16->pair;

    // Use KEMR to remove tmp edge and make an inner ring
    Face *r1 = EulerOps::KEMR(he_tmp, f6);

    // Use 4 MEV to create 4 inner columns
    HalfEdge *he17 = EulerOps::MEV(v9, 1, 1, 0, f_tmp);
    HalfEdge *he17_ = he17->pair;
    Vertex *v13 = he17->vert;
    HalfEdge *he18 = EulerOps::MEV(v10, 2, 1, 0, f_tmp);
    HalfEdge *he18_ = he18->pair;
    Vertex *v14 = he18->vert;
    HalfEdge *he19 = EulerOps::MEV(v11, 2, 2, 0, f_tmp);
    HalfEdge *he19_ = he19->pair;
    Vertex *v15 = he19->vert;
    HalfEdge *he20 = EulerOps::MEV(v12, 1, 2, 0, f_tmp);
    HalfEdge *he20_ = he20->pair;
    Vertex *v16 = he20->vert;

    // Use 4 MEF to create 4 new faces
    Face *f7 = EulerOps::MEF(v13, v14, f_tmp);
    HalfEdge *he21 = he17->next;
    HalfEdge *he21_ = he21->pair;
    Face *f8 = EulerOps::MEF(v14, v15, f_tmp);
    HalfEdge *he22 = he18->next;
    HalfEdge *he22_ = he22->pair;
    Face *f9 = EulerOps::MEF(v15, v16, f_tmp);
    HalfEdge *he23 = he19->next;
    HalfEdge *he23_ = he23->pair;
    Face *f10 = EulerOps::MEF(v16, v13, f_tmp);
    HalfEdge *he24 = he20->next;
    HalfEdge *he24_ = he24->pair;

    // Use KFMRH to remove a face and create an inner ring and a hole
    Face *r2 = EulerOps::KFMRH(f_tmp, f1);

    std::cout << "f1:" << std::endl;
    printFace(f1);
    std::cout << std::endl;

    std::cout << "f2:" << std::endl;
    printFace(f2);
    std::cout << std::endl;

    std::cout << "f3:" << std::endl;
    printFace(f3);
    std::cout << std::endl;

    std::cout << "f4:" << std::endl;
    printFace(f4);
    std::cout << std::endl;

    std::cout << "f5:" << std::endl;
    printFace(f5);
    std::cout << std::endl;

    std::cout << "f6:" << std::endl;
    printFace(f6);
    std::cout << std::endl;

    std::cout << "f7:" << std::endl;
    printFace(f7);
    std::cout << std::endl;

    std::cout << "f8:" << std::endl;
    printFace(f8);
    std::cout << std::endl;

    std::cout << "f9:" << std::endl;
    printFace(f9);
    std::cout << std::endl;

    std::cout << "f10:" << std::endl;
    printFace(f10);
    std::cout << std::endl;

    std::cout << "r1:" << std::endl;
    printFace(r1);
    std::cout << std::endl;

    std::cout << "r2:" << std::endl;
    printFace(r2);
    std::cout << std::endl;
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