#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to display the circular linked list
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
    struct Node *head = NULL, *newNode, *temp, *prev = NULL, *nextNode = NULL;
    int n, value;

    // Step 1: Create Circular Linked List with user input
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
            head->next = head; // circular link
        } else {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    printf("\nBefore reversal:\n");
    display(head);

    // Step 2: Reverse Circular Linked List
    if (head != NULL && head->next != head) {
        struct Node *last = head;
        while (last->next != head)
            last = last->next;

        temp = head;
        do {
            nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        } while (temp != head);

        // Fix last and head pointers
        head->next = prev;
        head = prev;
    }

    printf("\nAfter reversal:\n");
    display(head);

    return 0;
}
