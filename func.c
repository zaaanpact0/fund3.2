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

int is_equal_vector(const Vector *v1, const Vector *v2) {
    if (!v1 || !v2) return 0;
    if (v1->size != v2->size) return 0;
    
    for (size_t i = 0; i < v1->size; i++) {
        if (v1->CopyVoidPtr && v2->CopyVoidPtr) {
            VECTOR_TYPE copy1 = v1->CopyVoidPtr(v1->data[i]);
            VECTOR_TYPE copy2 = v2->CopyVoidPtr(v2->data[i]);
            
            if (copy1 != copy2) {
                if (v1->DeleteVoidPtr) v1->DeleteVoidPtr(copy1);
                if (v2->DeleteVoidPtr) v2->DeleteVoidPtr(copy2);
                return 0;
            }
            
            if (v1->DeleteVoidPtr) v1->DeleteVoidPtr(copy1);
            if (v2->DeleteVoidPtr) v2->DeleteVoidPtr(copy2);
        } else {
            if (v1->data[i] != v2->data[i]) {
                return 0;
            }
        }
    }
    
    return 1;
}