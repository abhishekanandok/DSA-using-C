#include <stdio.h>
#include <stdlib.h>

// Define the structure for the AVL tree node
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Function to get the height of a node
int getHeight(struct Node *n) {
    if (n == NULL)
        return 0;
    return n->height;
};

// Function to create a new node with the given key
struct Node *createNode(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially at height 1
    return node;
};

// Function to get the maximum of two integers
int maximum(int a, int b) {
    return ((a > b) ? a : b);
};

// Function to get the balance factor of a node
int getBalanceFactor(struct Node *n) {
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
};

// Function to right rotate subtree rooted with y
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = maximum(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = maximum(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
};

// Function to left rotate subtree rooted with x
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = maximum(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maximum(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
};

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct Node *insert(struct Node *node, int key) {
    // Perform the normal BST insertion
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    // Update height of this ancestor node
    node->height = 1 + maximum(getHeight(node->left), getHeight(node->right));

    // Get the balance factor of this ancestor node to check
    // whether this node became unbalanced
    int balance = getBalanceFactor(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
};

// A utility function to print preorder traversal of the tree.
void preOrder(struct Node *root) {
    if (root != NULL) {
        preOrder(root->left);
        printf("%d ", root->key);
        preOrder(root->right);
    }
};

// Driver code
int main() {
    struct Node *root = NULL;

    // Inserting nodes into the AVL tree
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 19);

    // Printing preorder traversal of the AVL tree
    printf("Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);

    return 0;
};
