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
int pop();
void Display1();
int isemply();
int peek();

int main()
{

    push(5);
    push(10);
    push(15);
    push(20);
    push(25);

    Display();

    pop();
    Display1();
    int poped = pop();
    printf("\nPoped element is : %d",poped);
    int top = peek();
    printf("\nTop element is : %d",top);
    
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
        printf("\n%d  ", p->data);
        p = p->next;
    }
}

int isemply()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop()
{
    node *temp;
    int val;
     if(isemply()){
        printf("Stacks underflow!!!");
        exit(1);
    }
    temp = top;
    val = temp->data;
    top = top->next;
    free(temp);
    temp = NULL;

    return val;

}

int peek()
{
    if(isemply()){
        printf("Stacks underflow!!!");
        exit(1);
    }
    return top->data;
}
void Display1()
{
    node *temp = top;

    if(isemply()){
        printf("Stacks underflow!!!");
        exit(1);
    }
    printf("\nStack elements are : ");
    while (temp != NULL)
    {
        printf("\n%d ",temp->data);
        temp= temp->next;
    }
    
}