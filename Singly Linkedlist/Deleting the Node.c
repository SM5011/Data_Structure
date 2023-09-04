#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void *delete_head(node *Head);
node *delete_last(node *Head);
void delete_pos(node **Head,int pos);

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

    current = (node *)malloc(sizeof(node));
    current->data = 25;
    current->next = NULL;

    Head->next->next->next = current;

    Head = delete_head(Head);
    Head = delete_last(Head);

    int pos = 3;
    delete_pos(&Head,pos);

    node *p = Head;
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->next;
    }
}

void *delete_head(node *Head)
{
    if (Head == NULL)
    {
        printf("List is already empty!!");
    }
    else
    {
        node *temp = Head;
        Head = Head->next;

        free(temp);
    }
    return Head;
}

node *delete_last(node *Head)
{

    if (Head == NULL)
    {
        printf("List is already Empty!!!");
    }
    else if (Head->next == NULL)
    {
        free(Head);
        Head = NULL;
    }
    else
    {
        node *temp = Head;
        node *temp2 = Head;

        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }

        temp2->next = NULL;
        free(temp);
        temp = NULL;

        return Head;
    }
}

void delete_pos(node **Head, int pos)
{
    node *current = *Head;
    node *previous = *Head;

    if (*Head == NULL)
    {
        printf("List is already Empty!!!");
    }
    else if (pos == 1)
    {
        *Head = current->next;
        free(current);
        current = NULL;
    }
    else
    {
        while (pos != 1)
        {
            previous = current;
            current = current->next;
            pos--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
    
}
