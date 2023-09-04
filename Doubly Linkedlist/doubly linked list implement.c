#include <stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} node;
node *addtoempty(int data, node *Head)
{
    node *creat_node = (node*)malloc(sizeof(node));
    creat_node->prev = NULL;
    creat_node->data = data;
    creat_node->next = NULL;

    Head = creat_node;
    return Head;
}
node *addatEnd(int data, node *Head)
{
    node *creat_node = (node*)malloc(sizeof(node));
    creat_node->prev = NULL;
    creat_node->data = data;
    creat_node->next = NULL;

    node *p=Head;
    while (p->next !=NULL)
    {
       p= p->next;
    }
    p->next = creat_node;
    creat_node->prev = p;
    
    return Head;
}
node *creatlist(node *Head)
{
    int n;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    if (n == 0)
    {
        return Head;
    }
    printf("Enter element of node 1 : ");
    int data;
    scanf("%d", &data);
    Head = addtoempty(data, Head);

    for (int i = 1; i < n; i++)
    {
        printf("Enter element of node %d : ", i + 1);
        scanf("%d", &data);
        Head = addatEnd(data, Head);
    }
    return Head;
}
int main()
{
    node *Head = NULL;
    Head = creatlist(Head);

    node *p = Head;
    while (p != NULL)
    {
        printf("%d - ", p->data);
        p = p->next;
    }
}
