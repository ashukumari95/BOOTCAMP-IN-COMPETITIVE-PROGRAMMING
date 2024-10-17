#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
struct node {
    int data;
    struct node* next; // 'next' points to the next node
};

// Declare front and rear pointers for the queue
struct node* front = 0;
struct node* rear = 0;

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

// Enqueue operation to add an element to the rear of the circular queue
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

    if (front == NULL) {
        // If the queue is empty, the new node becomes both front and rear
        front = newNode;
        rear = newNode;
        newNode->next = front; // Circular link: rear's next points to front
    } else {
        rear->next = newNode;  // Link the new node at the end of the queue
        rear = newNode;        // Rear becomes the new node
        rear->next = front;    // Rear's next points to front, making it circular
    }
    printf("%d enqueued to circular queue\n", value);
}

// Dequeue operation to remove an element from the front of the circular queue
void dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
        return;
    }

    int dequeuedValue;
    struct node* temp = front;

    if (front == rear) {
        // Only one element in the queue
        dequeuedValue = front->data;
        front = 0;
        rear = 0;
    } else {
        dequeuedValue = front->data;
        front = front->next;      // Move front to the next node
        rear->next = front;       // Rear's next points to new front, maintaining circular structure
    }

    free(temp); // Free the memory of the dequeued node
    printf("Dequeued value: %d\n", dequeuedValue);
}

// Display operation to show all elements in the circular queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front;
    printf("Circular queue elements: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front); // Loop continues until we reach the front again
    printf("(Back to front)\n");
}
