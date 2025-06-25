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
        printf("3. Front\n");
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
}

void enqueue(int n) {
    if ((rear + 1) % N == front) {
        printf("The queue is full.\n");
    } else {
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % N;
        }
        queue[rear] = n;
        printf("%d is enqueued to the queue.\n", n);
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("The queue is empty.\n");
    } else {
        printf("%d is dequeued from the queue.\n", queue[front]);
        if (front == rear) {
            // Only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % N;
        }
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("The queue is empty....!\n");
    } else {
        printf("%d is the front element in queue.\n", queue[front]);
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("The queue is empty....!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % N;
        }
        printf("\n");
    }
}
