//
// Created by Lucas Ismael Eckert on 06/01/2026.
//

#ifndef STUDYING_C_NUMBERS_H
#define STUDYING_C_NUMBERS_H

#include <stddef.h>

typedef struct {
    int *itens;
    size_t size;
    size_t capacity;
} ArrayList;

int init(ArrayList **nums_copy, size_t capacity);
void add(ArrayList *nums, int num);
void print(ArrayList *nums);

#endif
