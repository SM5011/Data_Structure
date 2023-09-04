#include <stdio.h>
#include <stdlib.h>
typedef struct Stacks
{
    int data;
    struct Stacks *next;
} stucks;
stucks *push(stucks *top, int data)
{
    stucks *new_node = (stucks *)malloc(sizeof(stucks));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;

    if (top == NULL)
    {
        top = new_node;
    }

    else
    {
        stucks *current = top;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }

    return top;
}
stucks *pop(stucks *top)
{
    if (top == NULL)
    {
        printf("Stucks is already empty!!");
        return 0;
    }

    else
    {

        while (top->next != NULL)
        {
            top = top->next;
        }
        stucks *current = top;
        current = current->next;
        free(current);
        current = NULL;
    }
    return top;
}
stucks *peak(stucks *top)
{
    if (top == NULL)
    {
        printf("Stucks is already empty!!");
    }
    else
    {
        stucks *current = top;
        while (current->next != NULL)
        {
            current = current->next;
        }
        printf("Peak element is : %d\n", current->data);
    }
}
int main()
{
    stucks *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    top = pop(top);
    top = push(top, 50);
    peak(top);

    stucks *p = top;
    printf("\nStucks :: ");
    while (p != NULL)
    {
        printf("\n elements are : %d ", p->data);
        p = p->next;
    }
}
