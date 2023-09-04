#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *top = NULL; // Declare top as a global variable

void push(int data);
void Display();

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Print\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter your data: ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            Display();
            break;
        case 3:
            exit(0);

        default:
            printf("Invalid entry!!\n");
            break;
        }
    }
}

void push(int data)
{
    node *Head = (node *)malloc(sizeof(node));

    if (Head == NULL)
    {
        printf("Stack is overflow..\n");
        exit(1);
    }
    Head->data = data;
    Head->next = top;
    top = Head;
}

void Display()
{
    node *p = top;

    while (p != NULL)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
}
