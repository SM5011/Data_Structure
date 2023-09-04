#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int data;
    struct Queue *next;

} queue;

void Display(queue *Head);
queue *enqueue(queue *Head, int data);
void *dequeue(queue *head);

int main()
{
    queue *Head = NULL;
    Head = enqueue(Head, 5);
    Head = enqueue(Head, 10);
    Head = enqueue(Head, 15);
    Head = enqueue(Head, 20);

    Display(Head);

    Head = dequeue(Head);

    Display(Head);
}

queue *enqueue(queue *Head, int data)
{

    queue *new = (queue *)malloc(sizeof(queue));
    new->data = data;
    new->next = NULL;

    if (Head == NULL)
    {
        Head = new;
    }
    else
    {
        queue *p = Head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = new;
    }
    return Head;
}
void *dequeue(queue *Head)
{
    if (Head == NULL)
    {
        printf("List is already empty!!");
    }
    else
    {
        int n = Head->data;
        printf("\nDequeued element is : %d",n);
        queue *temp = Head;
        Head = Head->next;

        free(temp);
    }
    return Head;
}
void Display(queue *Head)
{
    queue *p = Head;
    printf("\nQueue ::\n");
    while (p != NULL)
    {
        printf("%d--", p->data);
        p = p->next;
    }
}