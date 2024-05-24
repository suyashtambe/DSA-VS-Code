#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    char data[12];
    struct Node* next;
};

// Function to insert an element at a specific position in the linked list
void insertAtPosition(struct Node** head, int position, char value[12]) {
    if (*head == NULL) {
        printf("List is empty. Cannot insert at the specified position.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->data, value);

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    int currentPosition = 1;

    while (currentPosition < position - 1 && current->next != NULL) {
        current = current->next;
        currentPosition++;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize an empty list

    // Create a linked list with some initial elements
    for (int i = 5; i >= 1; i--) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        char aadhar[12];
        printf("Enter aadhar number: ");
        scanf("%s", aadhar);
        strcpy(newNode->data, aadhar);
        newNode->next = head;
        head = newNode;
    }

    printf("Original Linked List: ");
    printList(head);

    int position;
    char newemp[12];
    printf("Enter position to insert: ");
    scanf("%d", &position);
    printf("Enter new employee data: ");
    scanf("%s", newemp);

    insertAtPosition(&head, position, newemp);

    printf("Linked List After Insertion: ");
    printList(head);

    return 0;
}