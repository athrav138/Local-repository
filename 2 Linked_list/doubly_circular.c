#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to display the doubly circular linked list
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

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;

        if (head == NULL) {
            // First node: next and prev point to itself
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            // Insert at end (temporary)
            temp = head->prev;  // last node

            temp->next = newNode;
            newNode->prev = temp;

            newNode->next = head;
            head->prev = newNode;
        }
    }

    display(head);

    return 0;
}
