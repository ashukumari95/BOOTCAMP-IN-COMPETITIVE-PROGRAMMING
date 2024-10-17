//  1. write a program tha a lift management using  Queue ?

#include <stdio.h>
#define MAXSIZE 10

int Queue[MAXSIZE];
int front = -1;
int rear = -1;
int currentFloor = 0; // Lift starts at ground floor (0)

void insert();  // To add a request
void Delete();  // To process a request
void display(); // To show pending requests
void moveLift(int requestedFloor); // To move lift to requested floor

int main() {
    int choice;
    
    do {
        printf("\n1. Request Lift\n2. Process Next Request\n3. Display Requests\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                Delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the lift management system.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a floor request to the queue
void insert() {
    int floor;
    if ((rear + 1) % MAXSIZE == front) {
        printf("Queue is full. Cannot add more requests.\n");
    } else {
        printf("Enter the floor number to request the lift: ");
        scanf("%d", &floor);
        
        if (floor < 0 || floor >= MAXSIZE) {
            printf("Invalid floor number. Enter a number between 0 and %d.\n", MAXSIZE - 1);
            return;
        }

        if (front == -1 && rear == -1) {
            front = rear = 0;  // First element to be inserted
        } else {
            rear = (rear + 1) % MAXSIZE;
        }

        Queue[rear] = floor;
        printf("Floor %d request added to the queue.\n", floor);
    }
}

// Function to process (remove) a request from the queue
void Delete() {
    if (front == -1) {
        printf("Queue is empty. No requests to process.\n");
    } else {
        int requestedFloor = Queue[front];
        if (front == rear) {
            front = rear = -1;  // Reset the queue when the last element is processed
        } else {
            front = (front + 1) % MAXSIZE;
        }
        moveLift(requestedFloor); // Move the lift to the requested floor
    }
}

// Function to display the current requests in the queue
void display() {
    if (front == -1) {
        printf("No pending requests. Queue is empty.\n");
    } else {
        printf("Pending floor requests: ");
        int i = front;
        while (i != rear) {
            printf("%d ", Queue[i]);
            i = (i + 1) % MAXSIZE;
        }
        printf("%d\n", Queue[rear]);
    }
}

// Function to move the lift from the current floor to the requested floor
void moveLift(int requestedFloor) {
    printf("Lift is moving from floor %d to floor %d...\n", currentFloor, requestedFloor);
    currentFloor = requestedFloor;
    printf("Lift has arrived at floor %d.\n", currentFloor);
}
