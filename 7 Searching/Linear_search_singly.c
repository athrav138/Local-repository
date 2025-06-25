#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void search(struct Node* head, int key) {
    int pos = 1, found = 0;
    while (head != NULL) {
        if (head->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            found = 1;
        }
        head = head->next;
        pos++;
    }
    if (!found)
        printf("Element %d not found in list.\n", key);
}

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, val, key;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL)
            head = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    search(head, key);
    return 0;
}
