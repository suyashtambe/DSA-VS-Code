// B. Problem: Write a C program to create a Linked list of PAN numbers of 4 employees. Then
// insert the 5th employee’s PAN number at the beginning of the list.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for an employee node
struct emp {
    char name[50];
    char pan[11];
    struct emp* next;
};

// Function to create a new employee node with provided name and PAN
struct emp* createemp(char* name, char* pan) {
    struct emp* newemp = (struct emp*)malloc(sizeof(struct emp));
    strcpy(newemp->name, name);
    strcpy(newemp->pan, pan);
    newemp->next = NULL;
    return newemp;
}

int main() {
    // Create employee nodes and initialize them with name and PAN
    struct emp* emp1 = createemp("Suyash", "VBCRTWDV56");
    struct emp* emp2 = createemp("Tejas", "VBCRTWDV79");
    struct emp* emp3 = createemp("Jay", "VBCRTWDV90");
    struct emp* emp4 = createemp("Vedant", "VBCRTWDV45");
    struct emp* emp5 = createemp("Vaibhav", "VBCRTWDV60");

    // Connect the employee nodes to form a linked list
    emp1->next = emp2;
    emp2->next = emp3;
    emp3->next = emp4;
    emp5->next = emp1; // Note: emp5 is not connected to the main list

    // Traverse the linked list and print employee details
    struct emp* current = emp5; // Start from emp5
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("PAN: %s\n", current->pan);
        current = current->next;
    }

    // Free memory allocated for employee nodes
    free(emp1);
    free(emp2);
    free(emp3);
    free(emp4);
    // emp5 is not freed here since it's not part of the main list

    return 0;
}
