//singly linked list traversal 
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL; // Initialize head pointer to NULL
    struct node *newnode, *temp;

    int choice = 1;

    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) // Check if memory allocation is successful
        {
            printf("Memory allocation failed\n");
            // return 1; // Return with error code 1
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head =temp =  newnode; // If list is empty, make new node as head
        }
        else
        {
            temp->next = newnode; // Add new node at the end
            temp = newnode;
        }

        printf("Do you want to continue (1/0): ");
        scanf("%d", &choice);
    }

    printf("Linked List : ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        // count++ for display how many no of nodes
    }
      free(temp);
        return 0;
}