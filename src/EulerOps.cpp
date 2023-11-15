#include "EulerOps.h"

HalfEdge *EulerOps::MEV(Vertex *v, double x, double y, double z, Face *f)
{
    // create the new vertex
    Vertex *new_v = new Vertex(x, y, z);

    // create two half edges
    HalfEdge *new_he1 = new HalfEdge();
    HalfEdge *new_he2 = new HalfEdge();

    // set vertices of halfedges
    new_he1->vert = new_v;
    new_he2->vert = v;

    // set pair of halfedges
    new_he1->pair = new_he2;
    new_he2->pair = new_he1;

    // find insert vertex
    HalfEdge *current = f->edge;
    while (current->vert != v)
    {
        current = current->next;
        if (current == f->edge)
        {
            return nullptr;
        }
    }

    // insert the new halfedge
    new_he2->next = current->next;
    current->next = new_he1;
    new_he1->next = new_he2;

    // update face pointer
    new_he1->face = f;
    new_he2->face = f;

    // update edge pointer
    new_v->edge = new_he2;

    return new_he1;
}

Face *EulerOps::MEF(Vertex *v1, Vertex *v2, Face *f)
{
    // create two halfedges
    HalfEdge *new_he1 = new HalfEdge();
    HalfEdge *new_he2 = new HalfEdge();

    // set vertices of two halfedges
    new_he1->vert = v2;
    new_he2->vert = v1;

    // set pair relationship
    new_he1->pair = new_he2;
    new_he2->pair = new_he1;

    // create a new face
    Face *new_f = new Face();
    new_f->edge = new_he2;

    // update relationship between new halfedges and existing halfedges
    HalfEdge *current = v1->edge;
    HalfEdge *v1_prev_he = nullptr;
    HalfEdge *v2_prev_he = nullptr;
    while (current->vert != v2)
    {
        current = current->next;
    }
    v2_prev_he = current;
    while (current->vert != v1)
    {
        current = current->next;
    }
    v1_prev_he = current;
    v1_prev_he->next = new_he1;
    new_he1->next = v2_prev_he->next;
    v2_prev_he->next = new_he2;
    new_he2->next = v1->edge;
    v1->edge = new_he1;

    // update face pointer
    new_he1->face = f;
    new_he2->face = new_f;
    HalfEdge *temp = new_he2->next;
    while (temp != new_he2)
    {
        temp->face = new_f;
        temp = temp->next;
    }

    return new_f;
}

void EulerOps::KEMR(HalfEdge *he)
{
}