#include <stdio.h>
#include <string.h>
//reverse a string using stack

#define MAX_SIZE 100

struct Stack {
    int top;
    char array[MAX_SIZE];
};

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

void reverseString(char* str) {
    struct Stack stack;
    stack.top = -1;

    // Push each character onto the stack
    for (int i = 0; i < strlen(str); i++)
        push(&stack, str[i]);

    // Pop each character from the stack to reverse the string
    for (int i = 0; i < strlen(str); i++)
        str[i] = pop(&stack);
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    // Reverse the string
    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
