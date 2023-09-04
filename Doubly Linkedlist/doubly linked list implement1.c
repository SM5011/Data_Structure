#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} node;

node *createlist(int data, node *Head)
{
    node *create_node = (node *)malloc(sizeof(node));
    create_node->prev = NULL;
    create_node->data = data;
    create_node->next = NULL;

    if (Head == NULL)
    {
        Head = create_node;
    }
    else
    {
        node *p = Head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = create_node;
        create_node->prev = p;
    }

    return Head;
}
node *addatpos(int data, node *Head, int position)
{
    node *create_node = (node *)malloc(sizeof(node));
    create_node->prev = NULL;
    create_node->data = data;
    create_node->next = NULL;

    node *temp = Head, *temp2;
    while (position != 1)
    {
        temp = temp->next;
        position--;
    }
    if (temp->next == NULL)
    {
        temp->next = create_node;
        create_node->prev = temp;
    }
    else
    {
        temp2 = temp->next;
        temp->next = create_node;
        temp2->prev = create_node;
        create_node->prev = temp;
        create_node->next = temp2;
    }

    return Head;
}
node *deleteAtFirst(node *Head)
{
    node *temp = Head;
    Head = Head->next;
    free(temp);
    temp = NULL;
    Head->prev = NULL;
}
node *deleteAtLast(node *Head)
{
    node *temp = Head, *temp2;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp2 = temp->prev;
    temp2->next = NULL;

    free(temp);

    return Head;
}
int main()
{
    node *Head = NULL;
    Head = createlist(5, Head);
    Head = createlist(10, Head);
    Head = createlist(15, Head);
    Head = createlist(20, Head);

    Head = addatpos(50, Head, 3);

    Head = deleteAtFirst(Head);
    Head = deleteAtLast(Head);

    node *p = Head;
    while (p != NULL)
    {
        printf("%d - ", p->data);
        p = p->next;
    }
}
