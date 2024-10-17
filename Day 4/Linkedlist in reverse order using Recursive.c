#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct node {
    int data;
    struct node* next;
};

// Function prototypes
void print_reverse(struct node* head);
void insert_at_end(struct node** head, int data);

// Main function
int main() {
    struct node* head = NULL;

    // Inserting some values into the linked list
    insert_at_end(&head, 'A');
    insert_at_end(&head, 'B');
    insert_at_end(&head, 'C');
    insert_at_end(&head, 'D');
    
    printf("Original list: ");
    struct node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Printing the list in reverse order
    printf("Reversed list (using recursion): ");
    print_reverse(head);
    printf("NULL\n");

    return 0;
}

// Function to insert a new node at the end of the linked list
void insert_at_end(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

// Recursive function to print the linked list in reverse order
void print_reverse(struct node* head) {
    if (head == NULL) {
        return;
    }

    // Recursively call for the next node
    print_reverse(head->next);

    // Print the data of the current node after recursion has processed the next node
    printf("%d -> ", head->data);
}
