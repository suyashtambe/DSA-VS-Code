
// C. Problem: Write a C program to create a Linked list of Aadhar number of 4 employees. Then
// insert the 5th employee’s Aadhar number in the middle of the list.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for an employee node
struct emp {
    char aadhar[10];
    struct emp* next;
};

// Function to create a new employee node with the provided Aadhar number
struct emp* createemp(char* aadhar) {
    struct emp* newemp = (struct emp*)malloc(sizeof(struct emp));
    strcpy(newemp->aadhar, aadhar);
    newemp->next = NULL;
    return newemp;
}

int main() {
    // Create employee nodes and initialize them with Aadhar numbers
    struct emp* emp1 = createemp("123098456");
    struct emp* emp2 = createemp("329456891");
    struct emp* emp3 = createemp("329456190");
    struct emp* emp4 = createemp("323466891");
    struct emp* emp5 = createemp("065945689");

    // Connect the employee nodes to form a linked list
    emp1->next = emp2;
    emp2->next = emp3;
    emp3->next = emp4;

    emp5->next = emp3; // Link emp5 to emp3
    emp2->next = emp5; // Link emp2 to emp5

    // Traverse the linked list and print Aadhar numbers
    struct emp* current = emp1; // Start from emp1
    while (current != NULL) {
        printf("Aadhar: %s\n", current->aadhar);
        current = current->next;
    }

    // Free memory allocated for employee nodes
    free(emp1);
    free(emp2);
    free(emp3);
    free(emp4);
    free(emp5);

    return 0;
}

