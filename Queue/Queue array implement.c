#include <stdio.h>
#include <stdbool.h>

#define capacity 5

int myQueue[capacity];
int front = 0, totalitem = 0, rear = -1;

bool isempty()
{
    if (totalitem == 0)
    {
        return true;
    }
    return false;
}
bool isfull()
{
    if (totalitem == capacity)
    {
        return true;
    }
    return false;
}
void enqueue(int data)
{
    if (isfull())
    {
        printf("Queue is already full!!!");
        return;
    }
    rear = (rear + 1) % capacity; // last in
    myQueue[rear] = data;
    totalitem++;
}
int dequeue()
{
    if (isempty())
    {
        printf("Queue is already Empty!!!");
        return -1;
    }
    int frontdata = myQueue[front];
    myQueue[front] = -1;
    front = (front + 1) % capacity;
    totalitem--;
    return frontdata;
}
void printqueue()
{

    printf("\nQueue ::\n");
    for (int i = 0; i < capacity; i++)
    {
        printf("%d\n", myQueue[i]);
    }
}
int main()
{
    enqueue(5);
    enqueue(10);
    printqueue();
    enqueue(15);
    enqueue(20);
    enqueue(25);
    printqueue();
    enqueue(30);
    printqueue();
    dequeue();
    dequeue();
    printqueue();
    enqueue(35);
    printqueue();
}