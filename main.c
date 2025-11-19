#define VECTOR_TYPE int
#include "func.h"
#include <stdio.h>

int CopyInt(int value) {
    return value;
}

void DeleteInt(int value) {
    (void)value;
}

void print_menu() {
    printf("\n=== Menu ===\n");
    printf("1. Add element to vector\n");
    printf("2. Remove element by ind\n");
    printf("3. Access element by ind\n");
    printf("4. Duplicate vector to heap\n");
    printf("5. Check vector equality\n");
    printf("6. Clear vector contents\n");
    printf("7. Release heap vector\n");
    printf("0. Exit\n");
    printf("Choice: ");
}

void print_vector(Vector *v, const char *name_vector) {
    printf("%s: ", name_vector);
    if (!v) {
        printf("NULL\n");
        return;
    }

    for (size_t i = 0; i < v->size; i++) {
        printf("%d ", get_at_vector(v, i));
    }

    printf("\n");
}

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Vector v1 = create_vector(2, CopyInt, DeleteInt);
    Vector *v2 = NULL;

    int choice;
    int val;
    size_t ind;

    while (1) {
        printf("Current state:\n");
        print_vector(&v1, "v1");
        print_vector(v2, "v2");

        print_menu();

        if (scanf("%d", &choice) != 1) {
            clear_input();
            printf("Invalid input!\n");
            continue;
        }

        clear_input();

        switch(choice) {
            case 0: {
                erase_vector(&v1);
                delete_vector(v2);
                return 0;
            }

            case 1: {
                printf("Enter value: ");
                if (scanf("%d", &val) != 1) {
                    clear_input();
                    printf("Invalid input\n");
                    break;
                }

                clear_input();
                push_back_vector(&v1, val);
                break;
            }

            case 2: {
                printf("Enter index: ");
                if (scanf("%zu", &ind) != 1) {
                    clear_input();
                    printf("Invalid input\n");
                    break;
                }

                clear_input();
                if (ind < v1.size) {
                    delete_at_vector(&v1, ind);
                } else {
                    printf("Index out of range\n");
                }

                break;
            }

            case 3: {
                printf("Enter index: ");
                if (scanf("%zu", &ind) != 1) {
                    clear_input();
                    printf("Invalid input\n");
                    break;
                }

                clear_input();
                if (ind < v1.size) {
                    printf("%d\n", get_at_vector(&v1, ind));
                } else {
                    printf("Index out of range\n");
                }

                break;
            }

            case 4: {
                if (v2) {
                    printf("Already existsn\n");
                } else {
                    v2 = copy_vector_new(&v1);
                    if (!v2) {
                        printf("Fail\n");
                    }
                }

                break;
            }

            case 5: {
                if (!v2) {
                    printf("v2 = NULL\n");
                } else if (is_equal_vector(&v1, v2)) {
                    printf("definitely\n");
                } else {
                    printf("error\n");
                }

                break;
            }

            case 6: {
                erase_vector(&v1);
                break;
            }

            case 7: {
                delete_vector(v2);
                v2 = NULL;
                break;
            }

            default: {
                printf("Invalid choice\n");
                break;
            }
        }
    }
}