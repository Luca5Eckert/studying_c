//
// Created by Lucas Ismael Eckert on 06/01/2026.
//

#include "linked_list.h"

#include <stdlib.h>

int init(LinkedList **linked_list_copy) {
    LinkedList *linked_list = malloc(sizeof(LinkedList));
    if (!linked_list) {
        return -1;
    }

    linked_list->size = 0;
    linked_list->head = NULL;

    *linked_list_copy = linked_list;

    return 0;
}

int add(LinkedList *linked_list, int num) {
    Node *new_node = malloc(sizeof(Node));
    if (!new_node) {
        return -1;
    }
    new_node->data = num;
    new_node->next = NULL;

    Node *dummy = linked_list->head;
    if (!dummy) {
        linked_list->head = new_node;
        linked_list->size++;
        return 0;
    }

    while (dummy->next) {
        dummy = dummy->next;
    }

    dummy->next = new_node;
    linked_list->size++;

    return 0;
}

void remove(LinkedList *nums, Node *node);
void print(LinkedList *nums);
void clear(LinkedList *nums);

int main() {
    LinkedList *linked_list = NULL;
    init(&linked_list);
}
