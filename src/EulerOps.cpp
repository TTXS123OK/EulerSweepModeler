#include "EulerOps.h"

HalfEdge *EulerOps::MEV(Vertex *v, double x, double y, double z, Face *f) {
    // create the new vertex
    Vertex *new_v = new Vertex(x, y, z);

    // create two half edges
    HalfEdge *new_he = new HalfEdge();
    HalfEdge *new_he_ = new HalfEdge();

    // set vertices of half-edges
    new_he->vert = new_v;
    new_he_->vert = v;

    // update face pointer
    new_he->face = f;
    new_he_->face = f;

    // set pair relationship
    new_he->pair = new_he_;
    new_he_->pair = new_he;

    // insert new half-edges
    if (!v->edge) {
        new_he->next = new_he_;
        new_he_->next = new_he;
        v->edge = new_he;
        new_v->edge = new_he_;
        f->edge = new_he;
    } else {
        // find the half-edges that ends and start with v1
        HalfEdge *he, *he_;
        HalfEdge *current = f->edge;
        while (current->vert != v) {
            current = current->next;
        }
        he = current;
        he_ = he->next;
        he->next = new_he;
        new_he->next = new_he_;
        new_he_->next = he_;
        new_v->edge = new_he_;
    }

    return new_he;
}

Face *EulerOps::MEF(Vertex *v1, Vertex *v2, Face *f) {
    // create two half-edges
    HalfEdge *new_he = new HalfEdge();
    HalfEdge *new_he_ = new HalfEdge();

    // set pair relationship
    new_he->pair = new_he_;
    new_he_->pair = new_he;

    // set vertices of two half-edges
    new_he->vert = v2;
    new_he_->vert = v1;

    // find the half-edges that ends and start with v1
    HalfEdge *he1, *he1_;
    HalfEdge *current = f->edge;
    while (current->vert != v1) {
        current = current->next;
    }
    he1 = current;
    he1_ = he1->next;

    // find the half-edges that ends and start with v2
    HalfEdge *he2, *he2_;
    while (current->vert != v2) {
        current = current->next;
    }
    he2 = current;
    he2_ = he2->next;

    // reconstruct f's edges
    he1->next = new_he;
    new_he->next = he2_;
    current = new_he;
    do {
        current->face = f;
        current = current->next;
    } while (current != new_he);
    f->edge = new_he;

    // create a new face
    Face *new_f = new Face();
    new_f->edge = new_he_;
    he2->next = new_he_;
    new_he_->next = he1_;
    current = new_he_;
    do {
        current->face = new_f;
        current = current->next;
    } while (current != new_he_);

    return new_f;
}

Face *EulerOps::KEMR(HalfEdge *he) {

    HalfEdge *he_ = he->pair;

    // from he->next create a new ring
    Face *new_r = new Face();
    new_r->edge = he->next;
    HalfEdge *current = he->next;
    while (current->next != he_) {
        current->face = new_r;
        current = current->next;
    }
    current->next = he->next;

    // reconstruct face
    current = he_->next;
    while (current->next != he) {
        current = current->next;
    }
    current->next = he_->next;

    delete he;
    delete he_;
    return new_r;
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

Face *EulerOps::KFMRH(Face *face_to_kill) {
    return face_to_kill;
}