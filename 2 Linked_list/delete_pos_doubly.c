#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
    struct NODE *pre;
};

void delete_pos(struct NODE **head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct NODE *temp = *head;

    if (pos == 1) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->pre = NULL;
        free(temp);
        printf("Node deleted at position %d.\n", pos);
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position %d does not exist.\n", pos);
        return;
    }

    if (temp->pre != NULL)
        temp->pre->next = temp->next;

    if (temp->next != NULL)
        temp->next->pre = temp->pre;

    free(temp);
    printf("Node deleted at position %d.\n", pos);
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
    int n, element, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        insert_end(&head, element);
    }

    printf("Before deletion: ");
    display(head);

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    delete_pos(&head, pos);

    printf("After deletion: ");
    display(head);

    return 0;
}
