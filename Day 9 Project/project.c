#include <stdio.h>
#include <stdlib.h>

// Define a structure for a memory block
struct MemoryBlock {
    int size;
    int isFree;
    struct MemoryBlock* next;
};

// Head pointer for the linked list
struct MemoryBlock* head = NULL;

// Function to initialize memory
void initializeMemory(int size) {
    head = (struct MemoryBlock*) malloc(sizeof(struct MemoryBlock));
    head->size = size;
    head->isFree = 1;
    head->next = NULL;
}

// Function to allocate memory
void* allocateMemory(int size) {
    struct MemoryBlock* current = head;
    while (current != NULL) {
        if (current->isFree && current->size >= size) {
            current->isFree = 0;
            printf("Allocated %d bytes of memory\n", size);
            return (void*) (current + 1);
        }
        current = current->next;
    }
    printf("Memory allocation failed\n");
    return NULL;
}

// Function to deallocate memory
void deallocateMemory(void* ptr) {
    struct MemoryBlock* block = (struct MemoryBlock*)ptr - 1;
    block->isFree = 1;
    printf("Memory deallocated\n");
}

// Function to split a memory block if it is larger than requested
void splitMemoryBlock(struct MemoryBlock* block, int size) {
    if (block->size > size + sizeof(struct MemoryBlock)) {
        struct MemoryBlock* newBlock = (struct MemoryBlock*) ((char*) (block + 1) + size);
        newBlock->size = block->size - size - sizeof(struct MemoryBlock);
        newBlock->isFree = 1;
        newBlock->next = block->next;
        block->size = size;
        block->next = newBlock;
    }
}

// Function to print memory blocks
void printMemoryBlocks() {
    struct MemoryBlock* current = head;
    while (current != NULL) {
        printf("Block size: %d, Free: %d\n", current->size, current->isFree);
        current = current->next;
    }
}

int main() {
    int totalMemorySize = 1024;
    initializeMemory(totalMemorySize);

    printf("Initial memory blocks:\n");
    printMemoryBlocks();

    int allocSize1 = 200;
    void* ptr1 = allocateMemory(allocSize1);
    splitMemoryBlock(head, allocSize1);
    
    printf("\nMemory blocks after first allocation:\n");
    printMemoryBlocks();

    int allocSize2 = 300;
    void* ptr2 = allocateMemory(allocSize2);
    splitMemoryBlock(head->next, allocSize2);

    printf("\nMemory blocks after second allocation:\n");
    printMemoryBlocks();

    deallocateMemory(ptr1);

    printf("\nMemory blocks after deallocation of first block:\n");
    printMemoryBlocks();

    return 0;
}
