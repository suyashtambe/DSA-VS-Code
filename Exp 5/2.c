// question 2 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an employee's PAN number
struct Employee {
    char panNumber[11]; // Assuming PAN numbers are 10 characters long (plus '\0')
    struct Employee* next;
    struct Employee* prev;
};

// Function to create a new employee node
struct Employee* createEmployee(const char* pan) {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    if (newEmployee == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    strcpy(newEmployee->panNumber, pan);
    newEmployee->next = NULL;
    newEmployee->prev = NULL;
    return newEmployee;
}

// Function to insert an employee node at the beginning of the list
void insertAtBeginning(struct Employee** head, struct Employee* newEmployee) {
    if (*head == NULL) {
        *head = newEmployee;
    } else {
        newEmployee->next = *head;
        (*head)->prev = newEmployee;
        *head = newEmployee;
    }
}

// Function to print the list of employee PAN numbers
void printEmployees(struct Employee* head) {
    struct Employee* current = head;
    printf("Employee PAN Numbers:\n");
    while (current != NULL) {
        printf("%s\n", current->panNumber);
        current = current->next;
    }
}

int main() {
    struct Employee* head = NULL; // Initialize an empty list

    // Create employee nodes for 4 employees
    struct Employee* employee1 = createEmployee("117ABCDEFG");
    struct Employee* employee2 = createEmployee("109ABCDEFG");
    struct Employee* employee3 = createEmployee("121ABCDEFG");
    struct Employee* employee4 = createEmployee("125ABCDEFG");

    // Insert employees into the list
    insertAtBeginning(&head, employee1);
    insertAtBeginning(&head, employee2);
    insertAtBeginning(&head, employee3);
    insertAtBeginning(&head, employee4);

    // Insert the PAN number of the 5th employee at the beginning
    struct Employee* employee5 = createEmployee("094ABCDEFG");
    insertAtBeginning(&head, employee5);

    // Print the list of employee PAN numbers
    printEmployees(head);

    // Clean up: free memory allocated for employees
    while (head != NULL) {
        struct Employee* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}