#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the BST
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else if (value > root->value) {
        root->right = insertNode(root->right, value);
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

// Function to perform in-order traversal
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->value);
        inOrderTraversal(root->right);
    }
}

// Main function with menu-driven choice format
int main() {
    struct Node* root = NULL;
    int choice, value, searchKey;
    struct Node* searchResult;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Search for a Node\n");
        printf("3. Display In-order Traversal\n");
        printf("4. Exit\n");
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
                searchResult = searchNode(root, searchKey);
                if (searchResult != NULL) {
                    printf("Node with value %d found in the BST.\n", searchKey);
                } else {
                    printf("Node with value %d not found in the BST.\n", searchKey);
                }
                break;
            case 3:
                printf("In-order traversal of the BST: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
