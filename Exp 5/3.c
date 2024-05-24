// Problem C: Write a C program to create a Double Linked list of Aadhar number of 4 employees. Then
// insert the 5th employee’s Aadhar number in the middle of the list.
// Code:
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the doubly linked list
struct Node {
    long long aadharNumber;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node with given Aadhar number
struct Node* createNode(long long aadhar) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->aadharNumber = aadhar;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node in the middle of the doubly linked list
void insertInMiddle(struct Node* head, long long aadhar) {
    struct Node* newNode = createNode(aadhar);

    // Traverse to the middle of the list
    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Insert the new node after the middle node
    newNode->prev = slow;
    newNode->next = slow->next;
    if (slow->next != NULL) {
        slow->next->prev = newNode;
    }
    slow->next = newNode;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%lld -> ", current->aadharNumber);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the doubly linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    // Initialize an empty doubly linked list
    struct Node* head = createNode(123456789012); // Initial node

    // Input Aadhar numbers for 4 employees
    for (int i = 0; i < 4; i++) {
        long long aadhar;
        printf("Enter Aadhar number for employee %d: ", i + 1);
        scanf("%lld", &aadhar);

        // Insert the Aadhar number at the end of the list
        struct Node* newNode = createNode(aadhar);
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    // Print the original list
    printf("Original List: ");
    printList(head);

    // Input Aadhar number for the 5th employee
    long long aadhar5;
    printf("Enter Aadhar number for the 5th employee: ");
    scanf("%lld", &aadhar5);

    // Insert the Aadhar number in the middle of the list
    insertInMiddle(head, aadhar5);

    // Print the updated list
    printf("Updated List: ");
    printList(head);

    // Free the memory allocated for the list
    freeList(head);

    return 0;
}
