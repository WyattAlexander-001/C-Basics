#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an employee node
struct Customer {
    int id;
    char firstName[50];
    char lastName[50];
    char date[11]; // YYYY-MM-DD
    struct Customer* next;
};

// Function to print the linked list
void printList(struct Customer* n) {
    while (n != NULL) {
        printf("ID: %d, Name: %s %s, Date: %s\n",
               n->id, 
               n->firstName, 
               n->lastName, 
               n->date 
        );
        n = n->next;
    }
    printf("\n");
}


void push(struct Customer** head_ref, struct Customer new_customer) {
    struct Customer* new_node = (struct Customer*) malloc(sizeof(struct Customer));
    *new_node = new_customer;  // Copy all fields from new_emp to new_node
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Pop operation which removes the front employee from the list
int pop(struct Customer** head_ref) {
    if (*head_ref == NULL) return -1; // Consider -1 as an error code for empty list
    struct Customer* temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
    return 0; // Success
}

// Enqueue operation which adds a new employee to the end of the list
// void enqueue(struct Employee** head_ref, int id, char* firstName, char* lastName, char* dob, float payPerHour, char* jobTitle) {
//     struct Employee* new_node = (struct Employee*) malloc(sizeof(struct Employee));
//     struct Employee* last = *head_ref;
//     new_node->id = id;
//     strcpy(new_node->firstName, firstName);
//     strcpy(new_node->lastName, lastName);
//     strcpy(new_node->dob, dob);
//     new_node->payPerHour = payPerHour;
//     strcpy(new_node->jobTitle, jobTitle);
//     new_node->next = NULL;

//     if (*head_ref == NULL) {
//         *head_ref = new_node;
//         return;
//     }

//     while (last->next != NULL) {
//         last = last->next;
//     }

//     last->next = new_node;
// }

void enqueue(struct Customer** head_ref, struct Customer new_customer) {
    struct Customer* new_node = (struct Customer*) malloc(sizeof(struct Customer));
    struct Customer* last = *head_ref;
    *new_node = new_customer; // Copy all fields from new_emp to new_node
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

// Dequeue operation which removes the front employee from the list
int dequeue(struct Customer** head_ref) {
    return pop(head_ref); // Reuse pop for dequeue since it's identical
}

int main() {
    struct Customer* head = NULL;
    struct Customer olimar = {1, "Captain", "Olimar", "2024-12-31"};
    struct Customer louie = {2, "Louie", "Hocotate", "1990-12-17"};
    struct Customer alph = {3, "Alph", "Koppai", "1993-03-01"};
    struct Customer brittany = {4, "Brittany", "Koppai", "1995-06-23"};
    struct Customer charlie = {5, "Charlie", "Koppai", "1990-12-17"};
    
    // Testing Stack Operations
    push(&head, charlie);
    push(&head, louie);
    push(&head, olimar);
    printList(head); // Expected to print details of Olimar and Louie
    
    // Testing Queue Operations
    enqueue(&head, alph);
    enqueue(&head, brittany);
    printList(head); // Expected to print details of all three employees
    
    return 0;
}

// To compile: gcc -o deliLinkedList deliLinkedList.c
// To run: ./deliLinkedList