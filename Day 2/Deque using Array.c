#include <stdio.h>
#define SIZE 10

// Define the structure for the Deque
struct Deque {
    int items[SIZE];
    int front;
    int rear;
};

// Function prototypes
void insertFront(struct Deque* q, int value);
int deleteRear(struct Deque* q);
void display(struct Deque* q);
int isFull(struct Deque* q);
int isEmpty(struct Deque* q);

// Main function
int main() {
    struct Deque q;
    q.front = -1;
    q.rear = -1;

    int choice, value;

    do {
        printf("\n1. Insert at Front\n2. Delete from Rear\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&q, value);
                break;
            case 2:
                value = deleteRear(&q);
                if (value != -1) {
                    printf("Deleted %d from rear\n", value);
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

// Function to insert an element at the front of the deque
void insertFront(struct Deque* q, int value) {
    if (isFull(q)) {
        printf("Deque is full\n");
        return;
    }
    if (q->front == -1) { // Deque is initially empty
        q->front = 0;
        q->rear = 0;
    } else if (q->front == 0) {
        q->front = SIZE - 1; // Wrap around
    } else {
        q->front--;
    }
    q->items[q->front] = value;
    printf("Inserted %d at front\n", value);
}

// Function to delete an element from the rear of the deque
int deleteRear(struct Deque* q) {
    int element;
    if (isEmpty(q)) {
        printf("Deque is empty\n");
        return -1;
    }
    element = q->items[q->rear];

    if (q->front == q->rear) { // Deque has only one element
        q->front = -1;
        q->rear = -1;
    } else if (q->rear == 0) {
        q->rear = SIZE - 1; // Wrap around condition
    } else {
        q->rear--;
    }
    
    return element; // Return the deleted element
}

// Function to display the elements in the deque
void display(struct Deque* q) {
    if (isEmpty(q)) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque items: ");
    int i = q->front;
    if (q->front <= q->rear) {
        while (i <= q->rear) {
            printf("%d ", q->items[i]);
            i++;
        }
    } else {
        while (i < SIZE) {
            printf("%d ", q->items[i]);
            i++;
        }
        i = 0;
        while (i <= q->rear) {
            printf("%d ", q->items[i]);
            i++;
        }
    }
    printf("\n");
}

// Function to check if the deque is full
int isFull(struct Deque* q) {
    return (q->rear + 1) % SIZE == q->front;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* q) {
    return q->front == -1;
}
