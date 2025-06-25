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

// Insert at end
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

int main() {
    struct Node *head = NULL;
    int n, value;

    printf("Enter number of initial nodes: ");
    scanf("%d", &n);

    // Create initial list by inserting at end
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    display(head);

    // Insert at end new value
    printf("Enter value to insert at end: ");
    scanf("%d", &value);
    insertAtEnd(&head, value);

    display(head);

    return 0;
}
