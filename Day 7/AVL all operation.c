#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the AVL Tree
struct Node
{
  int value;
  struct Node *left;
  struct Node *right;
  int height;
};

// Function to get the height of the node
int height(struct Node *node)
{
  return node ? node->height : 0;
}

// Function to get the balance factor of a node
int getBalance(struct Node *node)
{
  return node ? height(node->left) - height(node->right) : 0;
}

// Function to create a new node
struct Node *createNode(int value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->value = value;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->height = 1; // New node is initially added at leaf
  return newNode;
}

// Right Rotate
struct Node *rightRotate(struct Node *y)
{
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  // Perform rotation
  x->right = y;
  y->left = T2;

  // Update heights
  y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
  x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

  // Return the new root
  return x;
}

// Left Rotate
struct Node *leftRotate(struct Node *x)
{
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  // Perform rotation
  y->left = x;
  x->right = T2;

  // Update heights
  x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
  y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

  // Return the new root
  return y;
}

// Function to insert a node in the AVL Tree
struct Node *insertNode(struct Node *node, int value)
{
  // 1. Perform the normal BST insertion
  if (node == NULL)
    return createNode(value);

  if (value < node->value)
    node->left = insertNode(node->left, value);
  else if (value > node->value)
    node->right = insertNode(node->right, value);
  else // Duplicate values are not allowed
    return node;

  // 2. Update the height of this ancestor node
  node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

  // 3. Get the balance factor of this ancestor node
  int balance = getBalance(node);

  // If the node becomes unbalanced, then there are 4 cases

  // Left Left Case
  if (balance > 1 && value < node->left->value)
    return rightRotate(node);

  // Right Right Case
  if (balance < -1 && value > node->right->value)
    return leftRotate(node);

  // Left Right Case
  if (balance > 1 && value > node->left->value)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  // Right Left Case
  if (balance < -1 && value < node->right->value)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  // return the (unchanged) node pointer
  return node;
}

// Function to find the node with the minimum value
struct Node *minValueNode(struct Node *node)
{
  struct Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Function to delete a node from the AVL Tree
struct Node *deleteNode(struct Node *root, int value)
{
  // STEP 1: PERFORM STANDARD BST DELETE
  if (root == NULL)
    return root;

  if (value < root->value)
    root->left = deleteNode(root->left, value);
  else if (value > root->value)
    root->right = deleteNode(root->right, value);
  else
  {
    // Node with only one child or no child
    if ((root->left == NULL) || (root->right == NULL))
    {
      struct Node *temp = root->left ? root->left : root->right;

      // No child case
      if (temp == NULL)
      {
        temp = root;
        root = NULL;
      }
      else             // One child case
        *root = *temp; // Copy the contents of the non-empty child
      free(temp);
    }
    else
    {
      // Node with two children: Get the inorder successor (smallest in the right subtree)
      struct Node *temp = minValueNode(root->right);
      root->value = temp->value;                          // Copy the inorder successor's data to this node
      root->right = deleteNode(root->right, temp->value); // Delete the inorder successor
    }
  }

  // If the tree had only one node then return
  if (root == NULL)
    return root;

  // STEP 2: UPDATE THE HEIGHT OF THE CURRENT NODE
  root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

  // STEP 3: GET THE BALANCE FACTOR OF THIS NODE
  int balance = getBalance(root);

  // If this node becomes unbalanced, then there are 4 cases

  // Left Left Case
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  // Left Right Case
  if (balance > 1 && getBalance(root->left) < 0)
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // Right Right Case
  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  // Right Left Case
  if (balance < -1 && getBalance(root->right) > 0)
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// Function for in-order traversal
void inOrderTraversal(struct Node *root)
{
  if (root != NULL)
  {
    inOrderTraversal(root->left);
    printf("%d ", root->value);
    inOrderTraversal(root->right);
  }
}

// Function for pre-order traversal
void preOrderTraversal(struct Node *root)
{
  if (root != NULL)
  {
    printf("%d ", root->value);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
}

// Function for post-order traversal
void postOrderTraversal(struct Node *root)
{
  if (root != NULL)
  {
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->value);
  }
}

// Main function
int main()
{
  struct Node *root = NULL;
  int choice, value;

  do
  {
    printf("\n1. Insert a node\n2. Delete a node\n3. In-order traversal\n4. Pre-order traversal\n5. Post-order traversal\n6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value to insert: ");
      scanf("%d", &value);
      root = insertNode(root, value);
      printf("Inserted %d into AVL Tree.\n", value);
      break;
    case 2:
      printf("Enter value to delete: ");
      scanf("%d", &value);
      root = deleteNode(root, value);
      printf("Deleted %d from AVL Tree.\n", value);
      break;
    case 3:
      printf("In-order traversal: ");
      inOrderTraversal(root);
      printf("\n");
      break;
    case 4:
      printf("Pre-order traversal: ");
      preOrderTraversal(root);
      printf("\n");
      break;
    case 5:
      printf("Post-order traversal: ");
      postOrderTraversal(root);
      printf("\n");
      break;
    case 6:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice! Please try again.\n");
    }
  } while (choice != 6);

      return 0;
}