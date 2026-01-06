#include "array_list.h"
#include <stdlib.h>
#include <stdio.h>

int init(ArrayList **array_copy, size_t capacity) {
    ArrayList *array = malloc(sizeof(ArrayList));
    if (!array) {
        return -1;
    }

    array->itens = malloc(sizeof(int) * capacity);
    if (!array->itens) {
        free(array);
        return -1;
    }

    array->capacity = capacity;
    array->size = 0;

    *array_copy = array;

    return 0;
}

void add(ArrayList *array, const int num) {
    if (array->size >= array->capacity) {
        array->capacity *= 2;

        int *temp = realloc(array->itens, array->capacity * sizeof(int));

        if (!temp) {
            printf("Memory allocation failed\n");
            return;
        }

        array->itens = temp;
    }

    array->itens[array->size] = num;
    array->size++;
}

int pop(ArrayList *array, const int index) {
    if (index < 0 || index >= array->size) {
        printf("Index out of bounds\n");
        return -1;
    }

    for (int i = index; i < array->size - 1; i++) {
        array->itens[i] = array->itens[i + 1];
    }

    array->size--;

    return 0;
}

void print(ArrayList *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->itens[i]);
    }
    printf("\n");
}

int main() {
    ArrayList *array;

    const int result = init(&array, 5);
    if (result != 0) {
        return -1;
    }

    add(array, 1);
    add(array, 2);
    add(array, 3);
    add(array, 4);
    add(array, 5);

    print(array);

    removeNumber(array, 0);
    removeNumber(array, 5); // Index out of bounds

    print(array);

    if (array) {
        free(array->itens);
        free(array);
    }

    return 0;
}
