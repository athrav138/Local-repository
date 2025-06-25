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

// Reverse the doubly circular linked list
void reverseList(struct Node **head_ref) {
    if (*head_ref == NULL) return;

    struct Node *current = *head_ref;
    struct Node *temp = NULL;

    do {
        // Swap next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to next node (which is prev before swapping)
        current = current->prev;
    } while (current != *head_ref);

    // Adjust head to new first node
    *head_ref = (*head_ref)->prev;
}

int main() {
    struct Node *head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    printf("Original list:\n");
    display(head);

    reverseList(&head);

    printf("Reversed list:\n");
    display(head);

    return 0;
}
