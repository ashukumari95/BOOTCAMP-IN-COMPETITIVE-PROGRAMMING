/*The idea to implement two stacks is to divide the array into two halves and assign 
two halves to two stacks, i.e., use arr[0] to arr[n/2] for stack1, and arr[(n/2) + 1] to arr[n-1] for 
stack2 where arr[] is the array to be used to implement two stacks and size of array be n. */

#include <stdio.h>
#define MAXSIZE 10

int arr[MAXSIZE];  // Array to store elements of both stacks
int top1 = -1;     // Stack1 pointer starting from index 0
int top2 = MAXSIZE; // Stack2 pointer starting from the last index

// Function prototypes
void push1(int data);   // Push element to stack1
void push2(int data);   // Push element to stack2
void pop1();            // Pop element from stack1
void pop2();            // Pop element from stack2
void display();         // Display both stacks

int main() {
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Push to Stack1\n2. Push to Stack2\n3. Pop from Stack1\n4. Pop from Stack2\n5. Display Stacks\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push into Stack1: ");
                scanf("%d", &data);
                push1(data);
                break;
            case 2:
                printf("Enter the value to push into Stack2: ");
                scanf("%d", &data);
                push2(data);
                break;
            case 3:
                pop1();
                break;
            case 4:
                pop2();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to push an element into Stack1
void push1(int data) {
    // Check if there's space for Stack1 (it should not collide with Stack2)
    if (top1 < top2 - 1) {
        top1++;
        arr[top1] = data;
        printf("Pushed %d into Stack1.\n", data);
    } else {
        printf("Stack1 overflow! No more space.\n");
    }
}

// Function to push an element into Stack2
void push2(int data) {
    // Check if there's space for Stack2 (it should not collide with Stack1)
    if (top2 > top1 + 1) {
        top2--;
        arr[top2] = data;
        printf("Pushed %d into Stack2.\n", data);
    } else {
        printf("Stack2 overflow! No more space.\n");
    }
}

// Function to pop an element from Stack1
void pop1() {
    if (top1 >= 0) {
        printf("Popped %d from Stack1.\n", arr[top1]);
        top1--;
    } else {
        printf("Stack1 underflow! No elements to pop.\n");
    }
}

// Function to pop an element from Stack2
void pop2() {
    if (top2 < MAXSIZE) {
        printf("Popped %d from Stack2.\n", arr[top2]);
        top2++;
    } else {
        printf("Stack2 underflow! No elements to pop.\n");
    }
}

// Function to display the elements of both stacks
void display() {
    int i;

    printf("Stack1 elements: ");
    if (top1 >= 0) {
        for (i = 0; i <= top1; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Stack1 is empty.\n");
    }

    printf("Stack2 elements: ");
    if (top2 < MAXSIZE) {
        for (i = MAXSIZE - 1; i >= top2; i--) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Stack2 is empty.\n");
    }
}
