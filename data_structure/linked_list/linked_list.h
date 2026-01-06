//
// Created by Lucas Ismael Eckert on 06/01/2026.
//

#ifndef STUDYING_C_LINKED_LIST_H
#define STUDYING_C_LINKED_LIST_H
#include <stddef.h>

typedef struct Node {
    struct node* next;
    void* data;
} Node;

typedef struct LinkedList {
    Node* head;
    size_t size;
} LinkedList;

int init(LinkedList *nums, size_t capacity);
void add(LinkedList *nums, void* data);
void remove(LinkedList *nums, Node *node);
void print(LinkedList *nums);
void clear(LinkedList *nums);


#endif //STUDYING_C_LINKED_LIST_H