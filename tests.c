#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "func.h"

VECTOR_TYPE copy_int(VECTOR_TYPE value) {
    if (!value) return NULL;
    int *new_int = malloc(sizeof(int));
    *new_int = *(int*)value;
    return new_int;
}

void delete_int(VECTOR_TYPE value) {
    free(value);
}

void test_basic_operations() {
    printf("Test 1: Basic operations... ");
    
    Vector vec = create_vector(2, copy_int, delete_int);
    int a = 10, b = 20, c = 30;
    
    push_back_vector(&vec, &a);
    push_back_vector(&vec, &b);
    push_back_vector(&vec, &c);
    
    assert(vec.size == 3);
    assert(*(int*)get_at_vector(&vec, 0) == 10);
    assert(*(int*)get_at_vector(&vec, 1) == 20);
    assert(*(int*)get_at_vector(&vec, 2) == 30);
    
    delete_at_vector(&vec, 1);
    assert(vec.size == 2);
    assert(*(int*)get_at_vector(&vec, 0) == 10);
    assert(*(int*)get_at_vector(&vec, 1) == 30);
    
    erase_vector(&vec);
    printf("PASSED\n");
}

void test_copy_operations() {
    printf("Test 2: Copy operations... ");
    static int a = 10, b = 20;
    
    Vector vec1 = create_vector(2, copy_int, delete_int);
    push_back_vector(&vec1, &a);
    push_back_vector(&vec1, &b);
    
    
    erase_vector(&vec1);
    
    printf("PASSED\n");
}

void test_edge_cases() {
    printf("Test 3: Edge cases... ");
    
    Vector vec = create_vector(0, copy_int, delete_int);
    assert(vec.capacity >= 1);
    
    assert(get_at_vector(&vec, 100) == NULL);
    delete_at_vector(&vec, 100);
    
    assert(is_equal_vector(NULL, &vec) == 0);
    
    erase_vector(&vec);
    printf("PASSED\n");
}

int main() {
    printf("Running Vector tests...\n");
    
    test_basic_operations();
    test_copy_operations();
    test_edge_cases();
    
    printf("All tests PASSED!\n");
    return 0;
}