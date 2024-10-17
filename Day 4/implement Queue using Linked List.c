#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
struct node {
    int data;
    struct node* next; // 'next' points to the next node
};

// Declare front and rear pointers for the queue
struct node* front = NULL;
struct node* rear = NULL;

// Function prototypes
void enqueue();
void dequeue();
void display();

// Main function
int main() {
    int choice;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

// Enqueue operation to add an element to the rear of the queue
void enqueue() {
    int value;
    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        // If queue is empty, both front and rear point to the new node
        front = rear = newNode;
    } else {
        // Add the new node to the end of the queue and update rear
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue\n", value);
}

// Dequeue operation to remove an element from the front of the queue
void dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
        return;
    }

    struct node* temp = front; // Temporary node to hold the front node
    int dequeuedValue = front->data;
    front = front->next; // Move front pointer to the next node

    if (front == NULL) {
        rear = NULL; // If the queue is now empty, set rear to NULL
    }

    free(temp); // Free the memory of the dequeued node
    printf("Dequeued value: %d\n", dequeuedValue);
}

// Display operation to show all elements in the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
