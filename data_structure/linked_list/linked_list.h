//
// Created by Lucas Ismael Eckert on 06/01/2026.
//

#ifndef STUDYING_C_LINKED_LIST_H
#define STUDYING_C_LINKED_LIST_H
#include <stddef.h>

typedef struct Node {
    struct Node* next;
    int data;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
    size_t size;
} LinkedList;

int init(LinkedList **nums);
int add(LinkedList *nums, int num);
int pop(LinkedList *linked_list, int position);
void print(const LinkedList *nums);
void clear(LinkedList *nums);


#endif