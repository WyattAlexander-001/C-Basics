#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an employee node
struct Employee {
    int id;
    char firstName[50];
    char lastName[50];
    char dob[11]; // YYYY-MM-DD
    float payPerHour;
    char jobTitle[100];
    struct Employee* next;
};

// Function to print the linked list
void printList(struct Employee* n) {
    while (n != NULL) {
        printf("ID: %d, Name: %s %s, DOB: %s, Pay: $%.2f/hr, Job: %s\n",
               n->id, n->firstName, n->lastName, n->dob, n->payPerHour, n->jobTitle);
               n = n->next;
    }
    printf("\n");
}

// Push operation which adds a new employee to the front of the list
// void push(struct Employee** head_ref, int id, char* firstName, char* lastName, char* dob, float payPerHour, char* jobTitle) {
//     struct Employee* new_node = (struct Employee*) malloc(sizeof(struct Employee));
//     new_node->id = id;
//     strcpy(new_node->firstName, firstName);
//     strcpy(new_node->lastName, lastName);
//     strcpy(new_node->dob, dob);
//     new_node->payPerHour = payPerHour;
//     strcpy(new_node->jobTitle, jobTitle);
//     new_node->next = *head_ref;
//     *head_ref = new_node;
// }

void push(struct Employee** head_ref, struct Employee new_emp) {
    struct Employee* new_node = (struct Employee*) malloc(sizeof(struct Employee));
    *new_node = new_emp;  // Copy all fields from new_emp to new_node
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Pop operation which removes the front employee from the list
int pop(struct Employee** head_ref) {
    if (*head_ref == NULL) return -1; // Consider -1 as an error code for empty list
    struct Employee* temp = *head_ref;
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

void enqueue(struct Employee** head_ref, struct Employee new_emp) {
    struct Employee* new_node = (struct Employee*) malloc(sizeof(struct Employee));
    struct Employee* last = *head_ref;
    *new_node = new_emp; // Copy all fields from new_emp to new_node
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
int dequeue(struct Employee** head_ref) {
    return pop(head_ref); // Reuse pop for dequeue since it's identical
}

int main() {
    struct Employee* head = NULL;
    struct Employee olimar = {1, "Captain", "Olimar", "1969-07-29", 45.0, "Space Captain"};
    struct Employee louie = {2, "Louie", "Hocotate", "1990-12-17", 38.0, "Assistant Captain"};
    struct Employee alph = {3, "Alph", "Koppai", "1993-03-01", 42.0, "Engineer"};
    struct Employee brittany = {4, "Brittany", "Koppai", "1995-06-23", 40.0, "Botanist"};
    struct Employee charlie = {5, "Charlie", "Koppai", "1990-12-17", 38.0, "Assistant Captain"};
    
    // Testing Stack Operations
    push(&head, louie);
    push(&head, olimar);
    printList(head); // Expected to print details of Olimar and Louie
    
    // Testing Queue Operations
    enqueue(&head, alph);
    enqueue(&head, brittany);
    printList(head); // Expected to print details of all three employees
    
    return 0;
}

// To compile: gcc -o employeeLinkedList employeeLinkedList.c
// To run: ./employeeLinkedList