#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    int age;
    struct Student* next;
    struct Student* prev;
};

// Function to create a new student node
struct Student* createStudent(int rollNumber, const char* name, int age) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    newStudent->rollNumber = rollNumber;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = NULL;
    newStudent->prev = NULL;
    return newStudent;
}

// Function to insert a student node at the end of the list
void insertAtEnd(struct Student** head, struct Student* newStudent) {
    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
        newStudent->prev = current;
    }
}

// Function to print the student list
void printStudents(struct Student* head) {
    struct Student* current = head;
    printf("Student Records:\n");
    while (current != NULL) {
        printf("Roll Number: %d, Name: %s, Age: %d\n", current->rollNumber, current->name, current->age);
        current = current->next;
    }
}

int main() {
    struct Student* head = NULL; // Initialize an empty list

    // Create student nodes and insert them into the list
    struct Student* student1 = createStudent(117, "suyash", 20);
    struct Student* student2 = createStudent(121, "Tejas", 20);
    struct Student* student3 = createStudent(109, "Jay", 20);

    // Insert students into the list
    insertAtEnd(&head, student1);
    insertAtEnd(&head, student2);
    insertAtEnd(&head, student3);

    // Print the list of students
    printStudents(head);

    // Clean up: free memory allocated for students
    while (head != NULL) {
        struct Student* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
