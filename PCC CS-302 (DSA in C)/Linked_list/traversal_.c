#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedTraversal(struct Node * ptr){
    while(ptr!=NULL)
    {
        printf("Element is : %d \n",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * forth;
    //allocate memory in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));
    //link first and second nodes
    head->data = 7;
    head->next = second;
    //link second and third values
    second->data = 11;
    second->next = third;

    //terminates the list at the third node
    third->data = 77;
    third->next = forth;

    forth->data = 34;
    forth->next = NULL;
    
    linkedTraversal(head);

    return 0;
}