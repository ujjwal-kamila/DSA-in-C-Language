// Write a C program to insert at begining,insert at end , delet from begining , delet from begining ,
//  delet from the end , delet and insert at a specific position and display elements in a Circular sigly linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
    }
}

void insertAfterPosition(struct Node* head, int position, int data) {
    if (head == NULL) {
        printf("List is empty. Insertion not possible.\n");
        return;
    }

    struct Node* current = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
        if (current == head) {
            printf("Position not found. Insertion not possible.\n");
            return;
        }
    }

    struct Node* newNode = createNode(data);
    newNode->next = current->next;
    current->next = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
        *head = newNode;
    }
}

void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    struct Node* temp = (*head)->next;
    if (temp == *head) {
        free(temp);
        *head = NULL;
    } else {
        (*head)->next = temp->next;
        free(temp);
    }
}

void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    struct Node* current = *head;
    while (current->next != *head) {
        current = current->next;
    }

    if (current == *head) {
        free(current);
        *head = NULL;
    } else {
        current->next = (*head)->next;
        free(*head);
        *head = current;
    }
}

void deleteFromPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    for (int i = 1; i < position; i++) {
        prev = current;
        current = current->next;
        if (current == head) {
            printf("Position not found. Deletion not possible.\n");
            return;
        }
    }

    if (current == head) {
        prev = current;
        while (prev->next != head) {
            prev = prev->next;
        }
    }

    prev->next = current->next;
    if (current == head) {
        //*head = prev;
        head = prev;
    }
    free(current);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        current = current->next;
        printf("%d\t", current->data);
    } while (current != head);
    //printf(" (Head)\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert after a specific position\n");
        printf("3. Insert at the end\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from a specific position\n");
        printf("7. Display the list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter position after which to insert: ");
                scanf("%d", &position);
                printf("Enter data to insert after position %d: ", position);
                scanf("%d", &data);
                insertAfterPosition(head, position, data);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                printf("Enter position from which to delete: ");
                scanf("%d", &position);
                deleteFromPosition(head, position);
                break;
            case 7:
                display(head);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    // Free memory before exiting
    while (head != NULL) {
        deleteFromBeginning(&head);
    }

    return 0;
}
