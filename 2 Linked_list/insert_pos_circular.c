#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, value, pos;

    // Input size of circular linked list
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create the circular linked list with user input values
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

    // Input position and value to insert
    printf("Enter position to insert new element: ");
    scanf("%d", &pos);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1) {
        // Insert at beginning
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    } else {
        // Insert at position > 1
        temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
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
