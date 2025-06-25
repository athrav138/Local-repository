#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
    struct NODE *pre;
};

void insert_pos(struct NODE **head, int element, int pos) {
    struct NODE *newnode = (struct NODE *)malloc(sizeof(struct NODE));
    newnode->data = element;

    if (pos <= 1 || *head == NULL) {
        newnode->next = *head;
        newnode->pre = NULL;
        if (*head != NULL)
            (*head)->pre = newnode;
        *head = newnode;
        return;
    }

    struct NODE *temp = *head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    newnode->next = temp->next;
    newnode->pre = temp;

    if (temp->next != NULL)
        temp->next->pre = newnode;

    temp->next = newnode;
}

void display(struct NODE *head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct NODE *head = NULL;
    int n, element, pos;

    printf("Enter initial number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        insert_pos(&head, element, i + 1); // insert at end-like position
    }

    printf("\nEnter new element to insert: ");
    scanf("%d", &element);
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    insert_pos(&head, element, pos);

    printf("Doubly Linked List: ");
    display(head);
    return 0;
}
