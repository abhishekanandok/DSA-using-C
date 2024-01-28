#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete a node with a given key
void deleteNode(struct Node **head, int key)
{
    if (*head == NULL)
    {
        return;
    }

    struct Node *temp = *head;

    // Find the node to be deleted
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    // If the node is not found
    if (temp == NULL)
    {
        printf("Node with key %d not found\n", key);
        return;
    }

    // Adjust pointers to skip the node to be deleted
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        *head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    // Free the memory of the deleted node
    free(temp);
}

// Function to display the doubly linked list
void displayList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the list
void freeList(struct Node **head)
{
    struct Node *temp = *head;
    struct Node *nextNode;

    while (temp != NULL)
    {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    *head = NULL; // Set head to NULL after freeing all nodes
}

// Main function for testing the doubly linked list
int main()
{
    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Doubly Linked List: ");
    displayList(head);

    insertAtBeginning(&head, 5);
    printf("After inserting 5 at the beginning: ");
    displayList(head);

    deleteNode(&head, 20);
    printf("After deleting node with key 20: ");
    displayList(head);

    freeList(&head); // Free memory before program exit

    return 0;
}
