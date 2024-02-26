// C  program to insert delet display elements in a linear queue 
#include <stdio.h>
#define N 5
int queue[N];
int front = -1, rear = -1;
int full()
{
    return (front == (rear + 1) % N);
}
int empty()
{
    return (front == -1);
}
void enqueue(int item)
{
    if (full())
    {
        printf("Overflow.\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % N;
    queue[rear] = item;
}
void dequeue()
{
    if (empty())
    {
        printf("Underflow\n");
        return;
    }
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % N;
}
void display()
{
    if (empty())
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    int i = front;
    do
    {
        printf("%d ", queue[i]);
        i = (i + 1) % N;
    } while (i != (rear + 1) % N);
    printf("\n");
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    dequeue();
    display();
    enqueue(5);
    enqueue(6);
    display();
    enqueue(7);
    display();
    return 0;
}