#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
    struct NODE *pre;
};

// Insert at end
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

// Display list
void display(struct NODE *head) {
    printf("List: ");
    while (head) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Reverse doubly linked list
void reverse(struct NODE **head) {
    struct NODE *temp = NULL;
    struct NODE *current = *head;

    // Swap next and pre for all nodes
    while (current != NULL) {
        temp = current->pre;
        current->pre = current->next;
        current->next = temp;
        current = current->pre;  // Move to next node (which is previous before swap)
    }

    // After the loop, temp points to the previous node of NULL (i.e., new head)
    if (temp != NULL)
        *head = temp->pre;
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

    printf("Original ");
    display(head);

    reverse(&head);

    printf("Reversed ");
    display(head);

    return 0;
}
