#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void display(struct Node *head) {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    struct Node *head = NULL, *temp, *newNode, *prev = NULL;
    int n, value, pos;

    // Step 1: Create circular linked list from user input
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    printf("\nOriginal ");
    display(head);

    // Step 2: Delete node at given position
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    if (head != NULL) {
        if (pos == 1) {
            temp = head;
            if (temp->next == head) { // only one node
                free(temp);
                head = NULL;
            } else {
                while (temp->next != head)
                    temp = temp->next;
                struct Node *toDelete = head;
                temp->next = head->next;
                head = head->next;
                free(toDelete);
            }
        } else {
            temp = head;
            int i = 1;
            while (i < pos && temp->next != head) {
                prev = temp;
                temp = temp->next;
                i++;
            }
            if (i == pos) {
                prev->next = temp->next;
                free(temp);
            } else {
                printf("Invalid position!\n");
            }
        }
    }

    printf("\nAfter deletion ");
    display(head);

    return 0;
}
