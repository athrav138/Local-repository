#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_pos(struct node **head, int value, int position);

int main() {
    struct node *new = NULL;
    struct node *tem = NULL;
    struct node *head = NULL;

    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        new = (struct node *)malloc(sizeof(struct node));
        printf("%d. Enter data: ", i + 1);
        scanf("%d", &new->data);

        new->next = NULL;

        if (head == NULL) {
            head = new;
            tem = head;
        } else {
            tem->next = new;
            tem = new;
        }
    }

    int element, pos;
    printf("Enter element to insert: ");
    scanf("%d", &element);
    printf("Enter position to insert (1 to %d): ", n);
    scanf("%d", &pos);

    insert_pos(&head, element, pos);

    tem = head;
    printf("Linked List: ");
    while (tem != NULL) {
        printf("%d -> ", tem->data);
        tem = tem->next;
    }
    printf("NULL\n");

    return 0;
}

void insert_pos(struct node **head, int value, int position) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
