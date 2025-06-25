#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, value;

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create circular linked list with user input
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

    // Insert new element at the end
    printf("Enter value to insert at the end: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        // If list is empty, new node points to itself
        newNode->next = newNode;
        head = newNode;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    // Display the circular linked list
    temp = head;
    if (head != NULL) {
        printf("Circular Linked List: ");
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
