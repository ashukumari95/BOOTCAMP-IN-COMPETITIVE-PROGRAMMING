#include <stdio.h>
#define MAXSIZE 10

int Queue[MAXSIZE];
int front = 0;
int rear = -1;

void insert();
void Delete();
void display();

int main() {
    int choice;
    
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

void insert() {
    int n;
    if (rear == MAXSIZE - 1) {
        printf("Queue overflow\n");
    } else {
        printf("Enter a number: ");
        scanf("%d", &n);
        rear++;
        Queue[rear] = n;
    }
}

void Delete() {
    if (front > rear) {
        printf("Queue underflow\n");
    } else {
        printf("Deleted element: %d\n", Queue[front]);
        front++;
    }
}

void display() {
    if (front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Queue[i]);
        }
        printf("\n");
    }
}