#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

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

void deleteAtBeg(struct Node **head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *head = *head_ref;
    if (head->next == head) {
        free(head);
        *head_ref = NULL;
        return;
    }

    struct Node *last = head->prev;
    struct Node *temp = head;

    last->next = head->next;
    head->next->prev = last;
    *head_ref = head->next;

    free(temp);
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

    deleteAtBeg(&head);
    printf("After deleting at beginning:\n");
    display(head);

    return 0;
}
