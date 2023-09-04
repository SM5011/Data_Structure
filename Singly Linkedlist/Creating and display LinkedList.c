#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

void Display(node *Head);
node *creat_linklist(int n);

int main()
{
    int n;
    node *Head = NULL;
    printf("Enter number of node : ");
    scanf("%d", &n);

    Head = creat_linklist(n);
    Display(Head);
}

node *creat_linklist(int n)
{
    node *Head = NULL;
    node *temp;
    node *p;

    for (int i = 0; i < n; i++)
    {
        temp = (node *)malloc(sizeof(node));
        printf("Enter data to the list %d. ", i + 1);
        scanf("%d", &(temp->data));
        temp->next = NULL;
        if (Head == NULL)
        {
            Head = temp;
        }
        else
        {
            p = Head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }

    return Head;
}
void Display(node *Head)
{
    node *p = Head;
    while (p != NULL)
    {
        printf("%d - ", p->data);
        p = p->next;
    }
}
