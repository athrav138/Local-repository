#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
    struct NODE *pre;
};

void delete_beg(struct NODE **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct NODE *temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
        (*head)->pre = NULL;

    free(temp);
    printf("Node deleted at beginning.\n");
}

void display(struct NODE *head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void insert_end(struct NODE **head, int element) {
    struct NODE *newnode = malloc(sizeof(struct NODE));
    newnode->data = element;
    newnode->next = NULL;
    newnode->pre = NULL;

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    struct NODE *temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = newnode;
    newnode->pre = temp;
}

int main() {
    struct NODE *head = NULL;
    int n, element;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        insert_end(&head, element);
    }

    printf("Before deletion: ");
    display(head);

    delete_beg(&head);

    printf("After deletion at beginning: ");
    display(head);

    return 0;
}
