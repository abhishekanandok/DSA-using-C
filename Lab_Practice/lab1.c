#include <stdio.h>
#define Max 5
int stack[Max];
int top = -1;

//stack using array

void push(int data)
{
    if (top == Max - 1)
    {
        printf("Stack overflow"

        );
    }
    else
    {
        top++;
        stack[top] = data;
        printf("inserted %d at index %d\n", data, top);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("empty stack");
    }
    else
    {

        printf("data deleted %d at index %d\n", stack[top], top);
        top--;
    }
}

void show()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    push(2);
    push(4);
    push(5);
    push(1);
    // push(1);
    // push(1);
    pop();
    show();

    return 0;
}