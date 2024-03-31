#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100
struct Stack
{
    int data[MAX_SIZE];
    int top;
};
void init(struct Stack *s)
{
    s->top = -1;
}
void push(struct Stack *s, int value)
{
    if (s->top >= MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = value;
}
int pop(struct Stack *s)
{
    if (s->top < 0)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}
int evaluatePostfix(char *expression)
{
    struct Stack stack;
    init(&stack);
    for (int i = 0; expression[i]; i++)
    {
        if (isdigit(expression[i]))
        {
            push(&stack, expression[i] - '0');
        }
        else
        {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (expression[i])
            {
            case '+':
                push(&stack, operand1 + operand2);
                break;
            case '-':
                push(&stack, operand1 - operand2);
                break;
            case '*':
                push(&stack, operand1 * operand2);
                break;
            case '/':
                push(&stack, operand1 / operand2);
                break;
            default:
                printf("Invalid operator\n");
                exit(1);
            }
        }
    }
    return pop(&stack);
}
int main()
{
    char postfixExpression[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfixExpression);
    int result = evaluatePostfix(postfixExpression);
    printf("Result: %d\n", result);
    return 0;
}