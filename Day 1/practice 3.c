                      //(A space-efficient implementation)

  /*
   The idea is to use two extra arrays for efficient implementation of k stacks in an array. 
   This may not make much sense for integer stacks, but stack items can be large for example
   stacks of employees, students, etc where every item is of hundreds of bytes. For such large
   stacks, the extra space used is comparatively very less as we use two integer arrays as extra space. 

    Following are the two extra arrays are used: 
          1) top[]: This is of size k and stores indexes of top elements in all stacks. 

          2) next[]: This is of size n and stores indexes of next item for the items in array arr[]. 

    Here arr[] is actual array that stores k stacks. Together with k stacks, a stack of free slots in arr[]
    is also maintained. The top of this stack is stored in a variable ‘free’. All entries in top[] are initialized
    as -1 to indicate that all stacks are empty. All entries next[i] are initialized as i+1 because all slots are 
    free initially and pointing to next slot. Top of free stack, ‘free’ is initialized as 0.
  */                    

 #include <stdio.h>
#include <limits.h>

#define MAX 10  // Array size
#define K 3     // Number of stacks

int arr[MAX];   // Array jo sabhi stacks ke elements ko store karega
int top[K];     // Array jo har stack ke top ka index store karega
int next[MAX];  // Next array jo next free slot ya next element ko manage karega
int free;       // Index of the first free slot

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
