#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Display function
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Doubly Circular Linked List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Insert at end (helper for initial creation)
void insertAtEnd(struct Node **head_ref, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head_ref == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head_ref = newNode;
        return;
    }

    struct Node *last = (*head_ref)->prev;

    newNode->next = *head_ref;
    newNode->prev = last;

    last->next = newNode;
    (*head_ref)->prev = newNode;
}

// Insert at position
void insertAtPosition(struct Node **head_ref, int value, int pos) {
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    // If list empty
    if (*head_ref == NULL) {
        if (pos == 1) {
            newNode->next = newNode;
            newNode->prev = newNode;
            *head_ref = newNode;
        } else {
            printf("Position out of bounds.\n");
            free(newNode);
        }
        return;
    }

    if (pos == 1) {
        // Insert at beginning
        struct Node *last = (*head_ref)->prev;

        newNode->next = *head_ref;
        newNode->prev = last;

        last->next = newNode;
        (*head_ref)->prev = newNode;

        *head_ref = newNode;
        return;
    }

    // Traverse to position-1 or last node
    struct Node *temp = *head_ref;
    int count = 1;
    while (count < pos - 1 && temp->next != *head_ref) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    struct Node *nextNode = temp->next;

    newNode->next = nextNode;
    newNode->prev = temp;

    temp->next = newNode;
    nextNode->prev = newNode;
}

int main() {
    struct Node *head = NULL;
    int n, value, pos;

    printf("Enter number of initial nodes: ");
    scanf("%d", &n);

    // Create initial list by inserting at end
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    display(head);

    printf("Enter value to insert: ");
    scanf("%d", &value);
    printf("Enter position to insert at: ");
    scanf("%d", &pos);

    insertAtPosition(&head, value, pos);

    display(head);

    return 0;
}
