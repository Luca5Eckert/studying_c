//
// Created by Lucas Ismael Eckert on 06/01/2026.
//

#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

int init(LinkedList  **linked_list_copy) {
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

    Node *dummy = linked_list->tail;
    if (!dummy) {
        linked_list->head = new_node;
        linked_list->tail = new_node;
        linked_list->size++;
        return 0;
    }

    dummy->next = new_node;
    linked_list->tail = new_node;
    linked_list->size++;

    return 0;
}

int pop(LinkedList *linked_list, int position) {
    if (position < 0 || position >= linked_list->size || linked_list->head == NULL) {
        return -1;
    }

    Node *node_to_remove = NULL;

    if (position == 0) {
        node_to_remove = linked_list->head;
        linked_list->head = node_to_remove->next;

        if (linked_list->size == 1) {
            linked_list->tail = linked_list->head;
        }
    } else {
        Node *prev = linked_list->head;

        for (int i = 0; i < position - 1; i++) {
            prev = prev->next;
        }

        node_to_remove = prev->next;
        prev->next = node_to_remove->next;

        if (node_to_remove == linked_list->tail) {
            linked_list->tail = prev;
        }
    }

    free(node_to_remove);
    linked_list->size--;

    return 0;
}

void print(const LinkedList *linked_list) {
    if (linked_list->size == 0) {
        return;
    }

    Node *dummy = linked_list->head;
    while (dummy) {
        printf("%d ", dummy->data);
        dummy = dummy->next;
    }
}

void clear(LinkedList *nums);

int main() {
    LinkedList *linked_list = NULL;
    init(&linked_list);
    add(linked_list, 1);
    print(linked_list);
}
