#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};
// Function to check if the stack is empty
int isEmpty(struct stack*ptr){
    if (ptr -> top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
// Function to check if the stack is full?
int isFull(struct stack * ptr){
    if(ptr -> top == ptr -> size -1){
        return 1;
    }
    else{
        return 0;
    }
}

// Stack Initialization
struct stack *initializeStack(int size) {
    struct stack *s = (struct stack *)malloc (sizeof(struct stack));
    if(s == NULL){
        printf("Failed Memory Allocation\n");
        exit(1);
    }
    s->size = size;
    s->top = -1;
    s->arr = (int *)malloc (s-> size * sizeof(int));
    if(s->arr == NULL){
        printf("Failed Memory Allocation\n");
        free(s);
        exit(1);
    }
    else {
        printf("Stack is Ready to use\n");
    }
    return s;
}

// Push function
void pushfun(struct stack *ptr , int value){
    if(isFull(ptr)){
        printf("Stack Overflow\n");
    }
    else{
        ptr->top++ ;
        ptr->arr[ptr->top] = value ;
        printf("Element %d pushed to the stack.\n", value);
    }
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        printf("Element %d popped from the stack.\n", value);
        return value;
    }
}

// Display function
void display(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack is empty.\n");
    } else {
        printf("Elements of the stack is : ");
        for (int i = 0; i <= ptr->top; i++) {
            printf("%d ", ptr->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct stack *s = initializeStack(50);
    int choice, element;

    do {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                pushfun(s, element);
                break;
            case 2:
                printf("Popped element: %d\n", pop(s));
                break;
            case 3:
                display(s);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    } while (choice != 4);

    free(s->arr);
    free(s);
    return 0;
}
