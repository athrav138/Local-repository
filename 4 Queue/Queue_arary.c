#include <stdio.h>
#define N 5

int queue[N];
int rear = -1, front = -1;

void enqueue(int n);
void dequeue();
void peek();
void display();

int main() {
    int choice, element;

    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element you want to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
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
                printf("Exiting....!\n");
                return 0;

            default:
                printf("Enter correct choice....!\n");
        }
    }
    return 0;
}

void enqueue(int n) {
    if (rear == N - 1) {
        printf("Queue Overflow....!\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = n;
        printf("%d enqueued at position %d.\n", n, rear);
    } else {
        rear++;
        queue[rear] = n;
        printf("%d enqueued at position %d.\n", n, rear);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("%d dequeued from position %d.\n", queue[front], front);
        front++;

        if (front > rear) {
            // Reset queue if it becomes empty
            front = rear = -1;
        }
    }
}

void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty....!\n");
    } else {
        printf("Front element is %d.\n", queue[front]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty...!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}