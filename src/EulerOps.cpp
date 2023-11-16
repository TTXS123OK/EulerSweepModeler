#include "EulerOps.h"

HalfEdge *EulerOps::MEV(Vertex *v, double x, double y, double z, Face *f) {
    // create the new vertex
    Vertex *new_v = new Vertex(x, y, z);

    // create two half edges
    HalfEdge *new_he1 = new HalfEdge();
    HalfEdge *new_he2 = new HalfEdge();

    // set vertices of half-edges
    new_he1->vert = new_v;
    new_he2->vert = v;

    // set pair relationship
    new_he1->pair = new_he2;
    new_he2->pair = new_he1;
    new_he2->next = nullptr;
    new_he1->next = nullptr;

    // update edge pointer
    v->edge = new_he1;
    new_v->edge = new_he2;

    // update face pointer
    new_he1->face = f;
    new_he2->face = f;

    if (!f->edge) {
        return new_he1;
    }

    // find insert vertex
    HalfEdge *current = f->edge;
    while (current->vert != v) {
        current = current->next;
        if (current == f->edge) {
            return nullptr;
        }
    }

    // insert the new half-edge
    current->next = new_he1;

    return new_he1;
}

Face *EulerOps::MEF(Vertex *v1, Vertex *v2, Face *f) {
    // create two half-edges
    HalfEdge *new_he1 = new HalfEdge();
    HalfEdge *new_he2 = new HalfEdge();

    // set vertices of two half-edges
    new_he1->vert = v2;
    new_he2->vert = v1;

    // set pair relationship
    new_he1->pair = new_he2;
    new_he2->pair = new_he1;

    // create a new face
    Face *new_f = new Face();
    new_f->edge = new_he2;

    // update relationship between new half-edges and existing half-edges
    if (v1->edge) {
        HalfEdge *current = v1->edge;
        HalfEdge *v1_prev_he;
        HalfEdge *v2_prev_he;
        while (current->next && current->vert != v2) {
            current = current->next;
        }
        v2_prev_he = current;
        while (current->next && current->vert != v1) {
            current = current->next;
        }
        v1_prev_he = current;
        v1_prev_he->next = new_he1;
        new_he1->next = v2_prev_he->next;
        v2_prev_he->next = new_he2;
        new_he2->next = v1->edge;
    }
    v1->edge = new_he1;
    v2->edge = new_he2;

    // update face pointer
    new_he1->face = f;
    new_he2->face = new_f;
    HalfEdge *temp = new_he2->next;
    while (temp != new_he2) {
        temp->face = new_f;
        temp = temp->next;
    }

    return new_f;
}

void EulerOps::KEMR(HalfEdge *he) {
    // input half-edge or its pair is null
    if (!he || !he->pair) {
        return;
    }

    Face *face1 = he->face;
    Face *face2 = he->pair->face;

    // invalid faces or both half-edges belong to the same face
    if (!face1 || !face2 || face1 == face2) {
        return;
    }

    // assign all half-edges of face2 to face1
    HalfEdge *current = he->pair;
    do {
        current->face = face1;
        current = current->next;
    } while (current != he->pair);

    // adjust the neighboring half-edges
    HalfEdge *he_pair_next = he->pair->next;
    HalfEdge *he_prev;
    HalfEdge *he_pair_prev;
    current = he;
    while (current->next != he) {
        current = current->next;
    }
    he_prev = current;
    current = he->pair;
    while (current->next != he->pair) {
        current = current->next;
    }
    he_pair_prev = current;

    he_prev->next = he_pair_next;
    he_prev->vert->edge = he_pair_next;

    he_pair_prev->next = he->next;
    he_pair_next->vert->edge = he->next;

    // delete the removed half-edges and clean up memory
    delete he->pair;
    delete he;

    // delete face2 and clean up memory
    delete face2;
}

Solid *EulerOps::MVFS(double x, double y, double z) {
    // create a new vertex
    Vertex *new_v = new Vertex(x, y, z);

    // create a new face
    Face *new_f = new Face();
    new_f->edge = nullptr;

    // create a new solid
    Solid *new_s = new Solid();
    new_s->faces.push_back(new_f);
    new_s->vertices.push_back(new_v);

    return new_s;
}