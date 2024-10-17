#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node* add; // Pointer to the next node
};

// Initialize the head pointer
struct node* start = NULL;

// Function prototypes
void menu();
void create();
void insert_first();
void insert_last();
void insert_middle();
void delete_first();
void delete_middle();
void display();

// Main function
int main() {
    menu();
    return 0;
}

// Function to display the menu
void menu() {
    int choice;
    do {
        printf("\nLinked List Menu:\n");
        printf("1. Create\n");
        printf("2. Insert at First\n");
        printf("3. Insert at Last\n");
        printf("4. Insert in Middle\n");
        printf("5. Delete from First\n");
        printf("6. Delete from Middle\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                create(); 
                break;
            case 2: 
                insert_first(); 
                break;
            case 3: 
                insert_last(); 
                break;
            case 4: 
                insert_middle(); 
                break;
            case 5: 
                delete_first(); 
                break;
            case 6: 
                delete_middle(); 
                break;
            case 7: 
                display(); 
                break;
            case 8: 
                exit(0);
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);
}

// Function to create the linked list
void create() {
    int n;
    char ch;

    printf("Enter element: ");
    scanf("%d", &n);
    
    start = (struct node*)malloc(sizeof(struct node)); // Create the first node
    start->data = n;
    start->add = NULL;

    printf("Do you want to add more elements? (y/Y to continue): ");
    while (1) {
        scanf(" %c", &ch); // Note the space before %c to ignore whitespace
        if (ch != 'y' && ch != 'Y') break;

        printf("Enter element: ");
        scanf("%d", &n);
        
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = n;
        new_node->add = NULL;

        struct node* temp = start;
        while (temp->add != NULL) { // Traverse to the end of the list
            temp = temp->add;
        }
        temp->add = new_node; // Link the new node
    }
}

// Function to insert a node at the beginning
void insert_first() {
    int n;
    printf("Enter element to insert at first: ");
    scanf("%d", &n);
    
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = n;
    new_node->add = start; // New node points to the current start
    start = new_node; // Update start to point to the new node
}

// Function to insert a node at the end
void insert_last() {
    int n;
    printf("Enter element to insert at last: ");
    scanf("%d", &n);
    
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = n;
    new_node->add = NULL; // New node's next will be NULL

    if (start == NULL) {
        start = new_node; // If the list is empty, the new node is the first node
    } else {
        struct node* temp = start;
        while (temp->add != NULL) {
            temp = temp->add; // Traverse to the end of the list
        }
        temp->add = new_node; // Link the new node
    }
}

// Function to insert a node in the middle
void insert_middle() {
    int n, pos, i = 1;
    printf("Enter element to insert in middle: ");
    scanf("%d", &n);
    printf("Enter the position where to insert: ");
    scanf("%d", &pos);

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = n;
    new_node->add = NULL;

    if (pos == 1) {
        new_node->add = start; // If inserting at position 1, update pointers
        start = new_node;
        return;
    }

    struct node* temp = start;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->add; // Traverse to the node before the desired position
        i++;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
    } else {
        new_node->add = temp->add; // Link new node to the next node
        temp->add = new_node; // Link previous node to the new node
    }
}

// Function to delete the first node
void delete_first() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = start;
    start = start->add; // Update start to the next node
    free(temp); // Free memory of the deleted node
}

// Function to delete a node from the middle
void delete_middle() {
    int pos, i = 1;
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    
    if (pos == 1) {
        delete_first(); // If deleting the first node, reuse the delete_first function
        return;
    }

    struct node* temp = start;
    struct node* prev = NULL;

    while (i < pos && temp != NULL) {
        prev = temp;
        temp = temp->add; // Traverse to the node to delete
        i++;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
    } else {
        prev->add = temp->add; // Link previous node to the next node
        free(temp); // Free memory of the deleted node
    }
}

// Function to display the linked list
void display() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = start;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->add; // Move to the next node
    }
    printf("NULL\n");
}
