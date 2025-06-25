#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Global front and rear pointers
struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front; // Circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Maintain circular link
    }
    printf("%d enqueued to queue\n", value);
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    if (front == rear) {
        printf("Dequeued: %d\n", front->data);
        free(front);
        front = rear = NULL;
    } else {
        struct Node *temp = front;
        printf("Dequeued: %d\n", temp->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

// Peek operation
void peek() {
    if (front == NULL) {
        printf("Queue is Empty\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

// Display operation
void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
