#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to insert at beginning
void insertAtBeg(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode; // points to itself
        *head = newNode;
    } else {
        struct Node *temp = *head;

        // Find the last node
        while (temp->next != *head) {
            temp = temp->next;
        }

        temp->next = newNode;     // last node points to newNode
        newNode->next = *head;    // newNode points to old head
        *head = newNode;          // head updated to newNode
    }
}

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create initial list by inserting at end
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;

        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
        } else {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Insert at beginning
    printf("Enter element to insert at beginning: ");
    scanf("%d", &value);
    insertAtBeg(&head, value);

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
