#include <stdio.h>
#include <stdlib.h>

// Structure for a stack node
struct node {
    int data;
    struct node* next; // 'next' points to the next node
};

// Declare the top pointer for the stack
struct node* top = NULL;

// Function prototypes
void push();
void pop();
void peek();
void display();

// Main function
int main() {
    int choice;

    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
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

// Push operation to add an element to the stack
void push() {
    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Heap overflow\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = top; // Link the new node to the previous top
    top = newNode; // Make the new node the top of the stack
    printf("%d pushed to stack\n", value);
}

// Pop operation to remove the top element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }

    struct node* temp = top; // Temporary node to hold the top node
    int poppedValue = top->data;
    top = top->next; // Move the top pointer to the next node
    free(temp); // Free the memory of the popped node
    printf("Popped value: %d\n", poppedValue);
}

// Peek operation to view the top element of the stack without removing it
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", top->data);
}

// Display operation to show all elements in the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
