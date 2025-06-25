#include <stdio.h>
#include <stdlib.h>

struct queue {
    int data;
    struct queue *next;
};

struct queue *rear = NULL;
struct queue *front = NULL;

void enqueue(int n);
void dequeue();
void peek();
void display();

int main() {
    int choice, num;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number you want to enqueue: ");
                scanf("%d", &num);
                enqueue(num);
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
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Enter a correct choice!\n");
        }
    }
    return 0;
}

void enqueue(int n) {
    struct queue *newNode = (struct queue *)malloc(sizeof(struct queue));
    newNode->data = n;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d is enqueued into the queue.\n", n);
}

void dequeue() {
    if (front == NULL) {
        printf("The queue is empty!\n");
        return;
    }

    struct queue *temp = front;
    printf("%d is dequeued from the queue.\n", temp->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL; // Queue is now empty
    }
    free(temp);
}

void peek() {
    if (front == NULL) {
        printf("The queue is empty!\n");
    } else {
        printf("Peek element is: %d\n", front->data);
    }
}

void display() {
    if (front == NULL) {
        printf("The queue is empty!\n");
        return;
    }

    struct queue *temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
