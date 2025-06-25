#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverseList(struct Node **head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse current node's pointer
        prev = curr;         // move prev one step forward
        curr = next;         // move curr one step forward
    }

    *head = prev;  // update head to new first node
}

int main() {
    struct Node *newnode = NULL, *head = NULL, *temp = NULL;
    int n;

    printf("Enter size of linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        if (newnode == NULL) {
            printf("Memory not allocated.\n");
            return 1;
        }

        printf("%d. Enter data: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("\nOriginal Linked List:\n");
    printList(head);

    reverseList(&head);

    printf("\nReversed Linked List:\n");
    printList(head);

    return 0;
}
