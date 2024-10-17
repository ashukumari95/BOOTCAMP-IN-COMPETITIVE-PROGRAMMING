// 2. implementation Queue operation using Array ?

#include <stdio.h>
#define MAXSIZE 5

int Queue[MAXSIZE];
int front = -1, rear = -1;

void enqueue();  // Function to add an element to the queue
void dequeue();  // Function to remove an element from the queue
void display();  // Function to display the elements in the queue

int main() {
    int choice;
    
    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add an element to the queue
void enqueue() {
    int item;

    // Check for queue overflow
    if (rear == MAXSIZE - 1) {
        printf("Queue is full (overflow). Cannot add more elements.\n");
        return;
    }

    // If the queue is empty, set front to 0
    if (front == -1) {
        front = 0;
    }

    // Input the element to enqueue
    printf("Enter the element to enqueue: ");
    scanf("%d", &item);
    
    // Add element at the rear of the queue
    rear++;
    Queue[rear] = item;
    printf("Enqueued element: %d\n", item);
}


 void dequeue() {
    // Check for queue underflow
    if (front == -1 || front > rear) {
        printf("Queue is empty (underflow). No elements to dequeue.\n");
        return;
    }

    // Dequeue the front element
    printf("Dequeued element: %d\n", Queue[front]);
    front++;

    // Reset the queue when all elements are dequeued
    if (front > rear) {
        front = rear = -1; // Reset queue if all elements are dequeued
    }
}

  void display() {
    // Check if the queue is empty
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Queue[i]);
        }
        printf("\n");
    }
}
