#include <stdio.h>
#include <stdlib.h>
//stack implemntation using linklist

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};


struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty stack
struct Stack *initializeStack()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    if (stack == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return (stack->top == NULL);
}


void push(struct Stack *stack, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}


int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        exit(EXIT_FAILURE);
    }

    struct Node *temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);

    return poppedValue;
}

// Function to get the top element of the stack without popping
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}


void displayStack(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    struct Node *current = stack->top;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the stack
void freeStack(struct Stack *stack)
{
    while (!isEmpty(stack))
    {
        pop(stack);
    }
    free(stack);
}

int main()
{
    struct Stack *anand = initializeStack();

    push(anand, 10);
    push(anand, 20);
    push(anand, 30);

    displayStack(anand);

    int poppedValue = pop(anand);
    printf("Popped element: %d\n", poppedValue);

    displayStack(anand);

    int topElement = peek(anand);
    printf("Top element: %d\n", topElement);


    freeStack(anand);

    return 0;
}
