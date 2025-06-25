#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct Node* temp = *head;

    // If deleting the first node
    if (position == 1) {
        *head = temp->next;
        printf("Deleted node with value: %d\n", temp->data);
        free(temp);
        return;
    }

    // Traverse to the (position - 1)th node
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    printf("Deleted node with value: %d\n", delNode->data);
    free(delNode);
}

int main() {
    struct Node* head = NULL;
    struct Node* newnode = NULL;
    struct Node* temp = NULL;
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter element %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Display before deletion
    printf("\nLinked list before deletion:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Delete from position
    int pos;
    printf("\nEnter position to delete (starting from 1): ");
    scanf("%d", &pos);
    deleteFromPosition(&head, pos);

    // Display after deletion
    printf("\nLinked list after deletion:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
