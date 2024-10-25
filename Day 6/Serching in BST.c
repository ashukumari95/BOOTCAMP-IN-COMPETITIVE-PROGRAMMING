#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the BST
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->value) {
        root->left = insertNode(root->left, data);
    } else if (data > root->value) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to search for a value in the BST
struct Node* searchNode(struct Node* root, int key) {
    if (root == NULL || root->value == key) {
        return root;
    }

    if (key < root->value) {
        return searchNode(root->left, key);
    }

    return searchNode(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int choice, value, searchKey;

    do {
        printf("\n1. Insert into BST\n2. Search in BST\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Enter value to search in the BST: ");
                scanf("%d", &searchKey);
                if (searchNode(root, searchKey) != NULL) {
                    printf("Node with value %d found in the BST.\n", searchKey);
                } else {
                    printf("Node with value %d not found in the BST.\n", searchKey);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
