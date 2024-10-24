#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

// Push operation which adds a new element to the stack
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Pop operation which removes the top element from the stack
int pop(struct Node** head_ref) {
    if (*head_ref == NULL) return -1; // Consider -1 as an error code for empty list
    struct Node* temp = *head_ref;
    int popped = temp->data;
    *head_ref = temp->next;
    free(temp);
    return popped;
}

// Enqueue operation which adds a new element to the queue
void enqueue(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Dequeue operation which removes the front element from the queue
// This is functionally equivalent to pop operation for a queue
int dequeue(struct Node** head_ref) {
    if (*head_ref == NULL) return -1; // Consider -1 as an error code for empty list
    struct Node* temp = *head_ref;
    int dequeued = temp->data;
    *head_ref = temp->next;
    free(temp);
    return dequeued;
}

int main() {
    struct Node* head = NULL;
    // Testing Stack Operations
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    printList(head); // Expected output: 3 2 1
    printf("Popped: %d\n", pop(&head)); // Pops 3
    printList(head); // Expected output: 2 1

    // Testing Queue Operations
    enqueue(&head, 4);
    enqueue(&head, 5);
    printList(head); // Expected output: 2 1 4 5
    printf("Dequeued: %d\n", dequeue(&head)); // Dequeues 2
    printList(head); // Expected output: 1 4 5

    return 0;
}

// To compile: gcc linkedListAdv.c -o linkedList
// To run: ./linkedListAdv