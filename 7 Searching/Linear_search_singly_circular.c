#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void search(struct Node* head, int key) {
    struct Node* temp = head;
    int pos = 1, found = 0;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    do {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            found = 1;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    if (!found)
        printf("Element %d not found in list.\n", key);
}

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
            temp->next = head;
        } else {
            temp->next = newNode;
            temp = newNode;
            temp->next = head;
        }
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    search(head, key);
    return 0;
}
