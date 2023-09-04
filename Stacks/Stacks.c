#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int data;
    struct Stack *next;
} stack;

stack *push(stack *top, int data)
{
    stack *new_node = (stack *)malloc(sizeof(stack));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = top; // Updated to push onto the top of the stack

    return new_node; // Return the new top
}

stack *pop(stack *top)
{
    if (top == NULL)
    {
        printf("Stack is already empty!!");
        return NULL; // Return NULL as the stack is empty
    }
    int poped_data = top->data;
    printf("\nPoped element is : %d",poped_data);
    stack *temp = top;
    top = top->next;
    free(temp);

    return top;
}

void peak(stack *top)
{
    if (top == NULL)
    {
        printf("\nStack is empty!!\n");
    }
    else
    {
        printf("\nPeak element is : %d\n", top->data);
    }
}

int main()
{
    stack *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    top = pop(top);
    top = push(top, 50);
    peak(top);

    stack *p = top;
    printf("\nStucks ::");
    while (p != NULL)
    {
        printf("\nElements are :%d ", p->data);
        p = p->next;
    }

    return 0;
}
