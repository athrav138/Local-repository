#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp, *newNode, *last;
    int n, value;

    // Take number of nodes from user
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input nodes from user and create circular linked list
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = newNode;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Delete at beginning
    if (head != NULL) {
        temp = head;
        if (temp->next == head) {
            free(temp);
            head = NULL;
        } else {
            last = head;
            while (last->next != head)
                last = last->next;
            last->next = head->next;
            temp = head;
            head = head->next;
            free(temp);
        }
    }

    // Display updated list
    temp = head;
    if (head != NULL) {
        printf("Circular Linked List after deleting at beginning: ");
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("(back to head)\n");
    } else {
        printf("List is empty.\n");
    }

    return 0;
}
