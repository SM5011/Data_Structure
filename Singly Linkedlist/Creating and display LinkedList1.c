#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *add_end(node *Head, int data);
void display(node *Head);

int main()
{
    node *Head = NULL;
    Head = add_end(Head, 10);
    Head = add_end(Head, 5);
    Head = add_end(Head, 15);
    Head = add_end(Head, 20);
    Head = add_end(Head, 25);

    printf("Original Linked List: ");
    display(Head);

    // Free the memory occupied by the linked list
    node *temp;
    while (Head != NULL)
    {
        temp = Head;
        Head = Head->next;
        free(temp);
    }

    return 0;
}

node *add_end(node *Head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (Head == NULL)
    {
        Head = newNode;
    }
    else
    {
        node *temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return Head;
}

void display(node *Head)
{
    node *current = Head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
