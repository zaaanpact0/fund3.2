#include "func.h"

Vector create_vector(size_t initial_capacity, VECTOR_TYPE (*CopyFunc)(VECTOR_TYPE), void (*DeleteFunc)(VECTOR_TYPE)) {

    Vector v;
    v.size = 0;
    v.capacity = initial_capacity > 0 ? initial_capacity : 1;
    v.CopyVoidPtr = CopyFunc;
    v.DeleteVoidPtr = DeleteFunc;

    v.data = (VECTOR_TYPE*)malloc(v.capacity * sizeof(VECTOR_TYPE));
    if (!v.data) {
        v.capacity = 0;
    }

    return v;
}

void erase_vector (Vector *v) {
    if (!v) return;

    if (v->DeleteVoidPtr && v->data) {
        for (size_t i = 0; i < v->size; i++) {
            v->DeleteVoidPtr(v->data[i]);
        }
    }

    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}