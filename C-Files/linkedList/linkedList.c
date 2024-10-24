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
}

int main() {
    // Create three nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Allocate memory for the nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Assign data to the nodes
    head->data = 1; // Assign data in the first node
    head->next = second; // Link the first node to the second node

    second->data = 2; // Assign data in the second node
    second->next = third; // Link the second node to the third node

    third->data = 3; // Assign data in the third node
    third->next = NULL; // Mark the end of the list

    // Print the linked list
    printList(head);

    return 0;
}

// To compile: gcc linkedList.c -o linkedList
// To run: ./linkedList


//Notes:
/*

struct Point {
    int x;
    int y;
};

struct Point *ptr = (struct Point *)malloc(sizeof(struct Point));
ptr->x = 10; // Equivalent to (*ptr).x = 10;
ptr->y = 20; // Equivalent to (*ptr).y = 20;


*/