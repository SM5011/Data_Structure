#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *add_beg(node *Head, int data);
node *add_last(node *Head, int data1);
node *add_pos(node *Head,int data2,int pos);

int main()
{
    node *Head = (node *)malloc(sizeof(node));
    Head->data = 10;
    Head->next = NULL;

    node *current = (node *)malloc(sizeof(node));
    current->data = 5;
    current->next = NULL;

    Head->next = current;

    current = (node *)malloc(sizeof(node));
    current->data = 15;
    current->next = NULL;

    Head->next->next = current;

    int data = 20;
    Head = add_beg(Head, data);

    int data1 = 25;
    current = add_last(Head, data1);

    int data2 =50, pos = 3;
    current = add_pos(Head, data2, pos);

    node *p = Head;
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->next;
    }
}

node *add_beg(node *Head, int data)
{
    node *current = (node *)malloc(sizeof(node));
    current->data = data;
    current->next = NULL;

    current->next = Head;

    Head = current;

    return Head;
}

node *add_last(node *Head, int data1)
{
    node *current = (node *)malloc(sizeof(node));
    current->data = data1;
    current->next = NULL;

    if (Head == NULL)
    {
        Head = current;
    }
    else
    {
        node *p = Head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = current;
    }

    return Head;
}

node *add_pos(node *Head, int data2, int pos)
{
    node *current = (node *)malloc(sizeof(node));
    current->data = data2;
    current->next = NULL;

    if (pos == 1)
    {
        current->next = Head;
        Head = current;
    }
    else
    {
        node *p = Head;
        for (int i = 1; i < pos - 1 && p != NULL; i++)
        {
            p = p->next;
        }
        if (p == NULL)
        {
            printf("Invalid position, node not inserted.\n");
            free(current); // Free the memory if position is invalid
        }
        else
        {
            current->next = p->next;
            p->next = current;
        }
    }

    return Head;
}
