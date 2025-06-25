#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Stack operations
void push1(int x) {
    if (top1 == MAX - 1) {
        printf("Stack1 Overflow\n");
        return;
    }
    stack1[++top1] = x;
}

int pop1() {
    if (top1 == -1) {
        printf("Stack1 Underflow\n");
        return -1;
    }
    return stack1[top1--];
}

void push2(int x) {
    if (top2 == MAX - 1) {
        printf("Stack2 Overflow\n");
        return;
    }
    stack2[++top2] = x;
}

int pop2() {
    if (top2 == -1) {
        printf("Stack2 Underflow\n");
        return -1;
    }
    return stack2[top2--];
}

// Queue operations
void enqueue(int x) {
    push1(x);
    printf("Enqueued: %d\n", x);
}

int dequeue() {
    if (top2 == -1) {
        if (top1 == -1) {
            printf("Queue is empty\n");
            return -1;
        } else {
            while (top1 != -1) {
                push2(pop1());
            }
        }
    }
    return pop2();
}

// Peek operation
int peek() {
    if (top2 == -1) {
        if (top1 == -1) {
            printf("Queue is empty\n");
            return -1;
        } else {
            while (top1 != -1) {
                push2(pop1());
            }
        }
    }
    return stack2[top2];  // Just return top of stack2
}

// Display queue
void display() {
    int i;
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    for (i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

// Main
int main() {
    int choice, val;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            val = dequeue();
            if (val != -1)
                printf("Dequeued: %d\n", val);
            break;
        case 3:
            val = peek();
            if (val != -1)
                printf("Front element: %d\n", val);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}