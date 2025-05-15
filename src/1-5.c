#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;  
} Node;

Node* create_node(int value) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->prev = new_node->next = NULL;
    return new_node;
}

int main() {
    Node* first   = create_node(1);
    Node* second = create_node(2);
    Node* third  = create_node(3);

    first->next    = second;
    second->prev  = first;
    second->next  = third;
    third->prev   = second;

    Node* tail = third;

    printf("Direct:\n");
    Node* curr = first;
    while (curr) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }

    printf("Reverse:\n");
    curr = tail;
    while (curr) {
        printf("%d\n", curr->data);
        curr = curr->prev;
    }

    curr = first;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }

    return 0;
}
