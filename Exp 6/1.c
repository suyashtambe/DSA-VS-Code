// Write a C program to create Menu driven program to do following operation on
// Circular Linked list
// 1. Create
// 2. Insert at any position
// 3. Delete from any position
// 4. Search the element and delete
// 5. Reverse

// CODE:
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

void print(struct node * head){
    if (head==NULL){
        printf("List is empty");
    }
    else{
        struct node *curr=(struct node *)malloc(sizeof(struct node));
        curr=head->next;
        printf("%d ->",head->data);
        while(curr!=head){
            printf("%d ->",curr->data);
            curr=curr->next;
        }
        printf("Circular");
    }
}

void create() {
    int n, value;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);

        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = value;

        if (head == NULL) {
            head = newnode;
            newnode->next = head;
        } else {
            struct node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }
    }

    printf("Circular Linked List created\n");
    print(head);
}

void insert() {
    if (head == NULL) {
        printf("Create a list first\n");
    } else {
        int position;
        printf("Enter the position you want to add element: ");
        scanf("%d", &position);

        if (position < 1 || position > countNodes() + 1) {
            printf("Invalid position. Please enter a valid position.\n");
            return;
        }

        struct node *curr = head;
        for (int j = 1; j < position - 1; j++) {
            curr = curr->next;
        }
        
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter new data: ");
        scanf("%d", &newnode->data);
        newnode->next = curr->next;
        curr->next = newnode;

        printf("Insertion done\n");
        print(head);
    }
}

int countNodes() {
    if (head == NULL) {
        return 0;
    }

    struct node *temp = head;
    int count = 0;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}


void delete(){
    if (head==NULL){
        printf("Create a list first");
    }
    else{
        int p;
        printf("Enter the position you want to delete from : ");
        scanf("%d",&p);
        struct node *curr=(struct node *)malloc(sizeof(struct node));
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        curr=head;
        for (int j=1;j<p-1;j++){
            curr=curr->next;
        }
        temp=curr->next;
        curr->next=curr->next->next;
        free(temp);
        printf("Deletion done\n");
        print(head);
    }
}


void search(){
    if (head==NULL){
        printf("Create a list first");
    }
    else{
        int p;
        printf("Enter the position you want to search : ");
        scanf("%d",&p);
        struct node *curr=(struct node *)malloc(sizeof(struct node));
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        curr=head;
        for (int j=1;j<p;j++){
            curr=curr->next;
        }
        printf("Data is : %d",curr->data);
    }
}


void reverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    (head)->next = prev;
    head = prev;
    
    struct node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf(" (Circular)\n");
}

int main(){
    int ch;
    do{
        printf("\n1 : Create\n");
        printf("2 : Insert\n");
        printf("3 : Delete\n");
        printf("4 : Search\n");
        printf("5 : Reverse\n");
        printf("6 : Exit\n");
        
        printf("Enter a choice : ");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
            create();
            break;
            case 2:
            insert();
            break;
            case 3:
            delete();
            break;
            case 4:
            search();
            break;
            case 5:
            reverse();
            break;
            case 6:
            exit(0);
            default:
            printf("Enter a valid choice!!\n");
            break;
        }
    }while(ch!=6);
    return 0;
}
