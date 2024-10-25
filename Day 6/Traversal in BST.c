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

// Function for In-order traversal
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->value);
        inOrderTraversal(root->right);
    }
}

// Function for Pre-order traversal
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function for Post-order traversal
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->value);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n1. Insert into BST\n2. In-order Traversal\n3. Pre-order Traversal\n4. Post-order Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("In-order traversal of the BST: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order traversal of the BST: ");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order traversal of the BST: ");
                postOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
