#include <stdio.h>
#include <stdlib.h>

// A tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// A utility function to create a new node
struct node* createNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node* root) {
    static struct node* prev = NULL;
    if (root != NULL) {
        if (!isBST(root->left)) {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data) {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else {
        return 1;
    }
}

struct node* inOrderPredecessor(struct node* root) {
    root = root->left;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct node* deleteNode(struct node* root, int value) {
    struct node* iPre;
    if (root == NULL) {
        return NULL;
    }
    // Searching for the node to be deleted
    if (value < root->data) {
        root->left = deleteNode(root->left, value); //root ke left me attatch kar do🫡
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);//root ke right me attatch kar do🫡
    }
    // Deletion strategy when the node is found
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder predecessor (largest in the left subtree)
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data); // ab root ke left se connect kar do🫡
    }
    return root;
}

int main() {
    // Constructing the root node - Using Function (Recommended)
    struct node* p = createNode(5);
    struct node* p1 = createNode(3);
    struct node* p2 = createNode(6);
    struct node* p3 = createNode(1);
    struct node* p4 = createNode(4);
    // Finally, the tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("InOrder before deletion:\n");
    inOrder(p);
    printf("\n");

    p = deleteNode(p, 5);

    printf("InOrder after deletion:\n");
    inOrder(p);
    printf("\n");

    return 0;
}
