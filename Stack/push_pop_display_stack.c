#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
struct Stack
{
    int items[MAX_SIZE];
    int top;
};
void initialize(struct Stack *s)
{
    s->top = -1;
}
void push(struct Stack *s, int value)
{
    s->items[++s->top] = value;
}
int pop(struct Stack *s)
{
    return s->items[s->top--];
}
void display(struct Stack *s)
{
    if (s->top >= 0)
    {
        printf("Stack contents:\n");
        for (int i = 0; i <= s->top; i++)
        {
            printf("%d\n", s->items[i]);
        }
    }
    else
    {
        printf("Stack is empty.\n");
    }
}
int main()
{
    struct Stack myStack;
    initialize(&myStack);
    int choice, element;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (myStack.top < MAX_SIZE - 1)
            {
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&myStack, element);
            }
            else
            {
                printf("Stack is full. Cannot push element.\n");
            }
            break;
        case 2:
            if (myStack.top >= 0)
            {
                printf("Popped element: %d\n",
                       pop(&myStack));
            }
            else
            {
                printf("Stack is empty. Cannot pop element.\n");
            }
            break;
        case 3:
            display(&myStack);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}