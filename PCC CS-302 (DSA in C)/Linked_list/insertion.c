//Linked list insertion 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedTraversal(struct Node * ptr){
    while(ptr!=NULL)
    {
        printf("Element is : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtBeginning(struct Node *head,int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node * insertAtIndex(struct Node *head,int data ,int index){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data =data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
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
    // head = insertAtBeginning(head,50);
    head = insertAtIndex(head,54,2);
    linkedTraversal(head);
    return 0;
}