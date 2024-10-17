#include <stdio.h>
#define MAXSIZE 10

// Define the structure for the Circular Queue
struct CircularQueue {
    int items[MAXSIZE];
    int front;
    int rear;
};

// Function prototypes
void enQueue(struct CircularQueue* q, int value);
int deQueue(struct CircularQueue* q);
void display(struct CircularQueue* q);
int isFull(struct CircularQueue* q);
int isEmpty(struct CircularQueue* q);

// Main function
int main() {
    struct CircularQueue q; // Create a CircularQueue instance
    q.front = -1; // Initialize front and rear
    q.rear = -1;
    int choice, value;

    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enQueue(&q, value);
                break;
            case 2:
                value = deQueue(&q);
                if (value != -1) {
                    printf("Deleted %d\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to insert an element into the circular queue
void enQueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }

    if (q->front == -1) {
        // Queue is initially empty
        q->front = 0;
    }

    // Circular increment
    q->rear = (q->rear + 1) % MAXSIZE;
    q->items[q->rear] = value;

    printf("Inserted %d\n", value);
}

// Function to delete an element from the circular queue
int deQueue(struct CircularQueue* q) {
    int element;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    element = q->items[q->front];

    if (q->front == q->rear) {
        // Queue is now empty
        q->front = -1;
        q->rear = -1;
    } else {
        // Circular increment
        q->front = (q->front + 1) % MAXSIZE;
    }

    return element;
}

// Function to display the elements of the circular queue
void display(struct CircularQueue* q) {
    int i;

    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Front -> %d\n", q->front);
    printf("Items -> ");

    // Traverse the circular queue
    for (i = q->front; i != q->rear; i = (i + 1) % MAXSIZE) {
        printf("%d ", q->items[i]);
    }
    // Print the last element
    printf("%d ", q->items[i]);
    printf("\n");
}

// Function to check if the queue is full
int isFull(struct CircularQueue* q) {
    return (q->rear + 1) % MAXSIZE == q->front;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* q) {
    return q->front == -1;
}
