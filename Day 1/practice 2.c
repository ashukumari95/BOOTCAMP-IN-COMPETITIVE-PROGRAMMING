                    //(Divide the array in slots of size n/k) 

 /*A simple way to implement k stacks is to divide the array in k slots of size n/k each, 
and fix the slots for different stacks, i.e., use arr[0] to arr[n/k-1] for first stack, 
and arr[n/k] to arr[2n/k-1] for stack2 where arr[] is the array to be used to implement 
two stacks and size of array be n. The problem with this method is inefficient use of 
array space. A stack push operation may result in stack overflow even if there is space 
available in arr[]. For example, say the k is 2 and array size (n) is 6 and we push 3 
elements to first and do not push anything to second stack. When we push 4th element to 
first, there will be overflow even if we have space for 3 more elements in array. */ 

#include <stdio.h>
#include <limits.h>

#define MAX 10  // Array ki size
#define K 3     // Number of stacks

int arr[MAX];   // Array jo sabhi stacks ke elements ko store karega
int top[K];     // Array jo har stack ke top ka index store karega
int next[MAX];  // Next array jo next free slot ya next element ko manage karega
int free;       // Pehla free slot ka index

// Sabhi stacks ko initialize karne ke liye function
void initializeKStacks() {
    for (int i = 0; i < K; i++) {
        top[i] = -1;  // Sabhi stacks ke tops ko -1 se initialize karein (empty stacks)
    }

    // Next array ko free slots ke liye set karein
    for (int i = 0; i < MAX - 1; i++) {
        next[i] = i + 1;
    }
    next[MAX - 1] = -1;  // Last slot ke baad koi free slot nahi hai, isliye -1

    free = 0;  // Pehla free slot 0 par hai
}

// Check karna ki array full hai ya nahi
int isFull() {
    return free == -1;
}

// Check karna ki stack empty hai ya nahi
int isEmpty(int stackNum) {
    return top[stackNum] == -1;
}

// Stack mein push karne ke liye function
void push(int stackNum, int value) {
    if (isFull()) {
        printf("Stack overflow!\n");
        return;
    }

    // Free slot ka index le lo
    int i = free;

    // Free ko next slot pe update karo
    free = next[i];

    // Naye element ko stack ke top se link karo
    next[i] = top[stackNum];

    // Stack ke top ko naye element pe update karo
    top[stackNum] = i;

    // Element ko array me insert karo
    arr[i] = value;

    printf("Pushed %d to stack %d.\n", value, stackNum + 1);
}

// Stack se pop karne ke liye function
int pop(int stackNum) {
    if (isEmpty(stackNum)) {
        printf("Stack underflow!\n");
        return INT_MIN;
    }

    // Stack ke top element ka index le lo
    int i = top[stackNum];

    // Stack ke top ko next element pe update karo
    top[stackNum] = next[i];

    // Is slot ko wapas free list me daal do
    next[i] = free;
    free = i;

    return arr[i];
}

// Specific stack ke elements ko display karne ka function
void displayStack(int stackNum) {
    if (isEmpty(stackNum)) {
        printf("Stack %d is empty.\n", stackNum + 1);
        return;
    }

    printf("Elements of stack %d: ", stackNum + 1);
    int i = top[stackNum];
    while (i != -1) {
        printf("%d ", arr[i]);
        i = next[i];
    }
    printf("\n");
}

int main() {
    initializeKStacks();

    push(0, 10); // Stack 1 me 10 push karo
    push(1, 20); // Stack 2 me 20 push karo
    push(0, 30); // Stack 1 me 30 push karo
    push(2, 40); // Stack 3 me 40 push karo
    push(1, 50); // Stack 2 me 50 push karo
    push(2, 60); // Stack 3 me 60 push karo

    displayStack(0);  // Stack 1 ko display karo
    displayStack(1);  // Stack 2 ko display karo
    displayStack(2);  // Stack 3 ko display karo

    printf("Popped element from stack 1: %d\n", pop(0));  // Stack 1 se pop karo
    printf("Popped element from stack 2: %d\n", pop(1));  // Stack 2 se pop karo

    displayStack(0);  // Stack 1 ko fir se display karo
    displayStack(1);  // Stack 2 ko fir se display karo

    return 0;
}
