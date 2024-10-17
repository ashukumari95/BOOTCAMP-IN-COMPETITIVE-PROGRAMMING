#include <stdio.h>
#include <stdlib.h>

// structure of a node
struct node {
    int data;
    struct node *add; // correct the typo 'nose' to 'node'
};

// Declare the head pointer
struct node *start = NULL, *temp, *new1, *prev, *next;

// Function prototypes
void insert_first();
void insert_last();
void insert_middle();
void display();

// main function
int main() {
    int choice;

    do {
        printf("\n1. Insert at First\n2. Insert at Last\n3. Insert in Middle\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insert_first();
                break;
            case 2:
                insert_last();
                break;
            case 3:
                insert_middle();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    
    return 0;
}

// Insert at first position
void insert_first() {
    int n; // to assign data value to new create node to insert

    printf("Enter new element to insert: ");
    scanf("%d", &n);

    new1 = (struct node*)malloc(sizeof(struct node)); // creating new node
    new1->data = n; // assigning n to data
    new1->add = start; // so that the current start becomes the second node
    start = new1; // update start to the new node
}

// Insert at last position
void insert_last() {
    int n; // to assign data value to new create node to insert
    printf("Enter new element to insert: ");
    scanf("%d", &n);

    new1 = (struct node*)malloc(sizeof(struct node)); // creating new node
    new1->data = n; // assigning n to data
    new1->add = NULL; // new node's next will be NULL as it will be the last node

    if (start == NULL) {
        // If list is empty, the new node will be the first node
        start = new1;
    } else {
        temp = start;
        while (temp->add != NULL) {
            temp = temp->add; // traverse until the last node
        }
        temp->add = new1; // make the last node's 'add' point to the new node
    }
}

// Insert at middle position
void insert_middle() {
    int n, pos, i = 1; // i=1 is to run loop for finding position of node to insert

    if (start == NULL) {
        printf("List not found\n");
        return;
    }

    printf("Enter new element to insert: ");
    scanf("%d", &n);

    new1 = (struct node*)malloc(sizeof(struct node)); // creating new node
    new1->data = n; // assigning n to data
    new1->add = NULL; // default to NULL

    printf("Enter the position where node needs to be inserted: ");
    scanf("%d", &pos); // get the position where we want to insert node

    if (pos == 1) {
        new1->add = start; // make new node point to start
        start = new1; // new node becomes the start
        return;
    }

    next = start;
    while (i < pos && next != NULL) {
        prev = next;
        next = next->add;
        i++;
    }

    if (next == NULL && i < pos) {
        printf("Position out of bounds\n");
    } else {
        prev->add = new1; // link the previous node to the new node
        new1->add = next; // link new node to the next node
    }
}

// Function to display the linked list
void display() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->add;
    }
    printf("NULL\n");
}
