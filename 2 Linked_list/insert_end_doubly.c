#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
    struct NODE *pre;
};

void insert_end(struct NODE **head, int element) {
    struct NODE *newnode = (struct NODE *)malloc(sizeof(struct NODE));
    newnode->data = element;
    newnode->next = NULL;
    newnode->pre = NULL;

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    struct NODE *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->pre = temp;
}

void display(struct NODE *head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct NODE *head = NULL;
    int n, element;

    // First scan list elements
    printf("Enter the size of doubly linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        insert_end(&head, element);
    }

    // Scan the element to insert at end
    printf("Enter element to insert at the end: ");
    scanf("%d", &element);
    insert_end(&head, element);

    // Display updated list
    display(head);

    return 0;
}
