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
    struct Node *head = NULL, *temp, *newNode, *prev = NULL;
    int n, value;

    // Step 1: User input to create circular linked list
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

    printf("\nBefore deletion:\n");
    display(head);

    // Step 2: Delete node at end
    if (head != NULL) {
        temp = head;
        if (temp->next == head) { // only one node
            free(temp);
            head = NULL;
        } else {
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            free(temp);
        }
    }

    printf("\nAfter deleting last node:\n");
    display(head);

    return 0;
}
