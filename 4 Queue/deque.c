#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int frontStack[MAX], rearStack[MAX];
int topFront = -1, topRear = -1;

// Stack operations
void pushFront(int x) {
    if (topFront == MAX - 1) {
        printf("Front Stack Overflow\n");
        return;
    }
    frontStack[++topFront] = x;
}

int popFront() {
    if (topFront == -1) {
        printf("Front Stack Underflow\n");
        return -1;
    }
    return frontStack[topFront--];
}

void pushRear(int x) {
    if (topRear == MAX - 1) {
        printf("Rear Stack Overflow\n");
        return;
    }
    rearStack[++topRear] = x;
}

int popRear() {
    if (topRear == -1) {
        printf("Rear Stack Underflow\n");
        return -1;
    }
    return rearStack[topRear--];
}

// Deque operations
void insertFront(int x) {
    pushFront(x);
    printf("Inserted at front: %d\n", x);
}

void insertRear(int x) {
    pushRear(x);
    printf("Inserted at rear: %d\n", x);
}

int deleteFront() {
    if (topFront == -1) {
        if (topRear == -1) {
            printf("Deque is empty\n");
            return -1;
        } else {
            while (topRear != -1)
                pushFront(popRear());
        }
    }
    return popFront();
}

int deleteRear() {
    if (topRear == -1) {
        if (topFront == -1) {
            printf("Deque is empty\n");
            return -1;
        } else {
            while (topFront != -1)
                pushRear(popFront());
        }
    }
    return popRear();
}

int peekFront() {
    if (topFront == -1) {
        if (topRear == -1) {
            printf("Deque is empty\n");
            return -1;
        } else {
            while (topRear != -1)
                pushFront(popRear());
        }
    }
    return frontStack[topFront];
}

int peekRear() {
    if (topRear == -1) {
        if (topFront == -1) {
            printf("Deque is empty\n");
            return -1;
        } else {
            while (topFront != -1)
                pushRear(popFront());
        }
    }
    return rearStack[topRear];
}

void display() {
    if (topFront == -1 && topRear == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = topFront; i >= 0; i--)
        printf("%d ", frontStack[i]);
    for (int i = 0; i <= topRear; i++)
        printf("%d ", rearStack[i]);
    printf("\n");
}

// Main function
int main() {
    int choice, val;

    while (1) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear");
        printf("\n5. Peek Front\n6. Peek Rear\n7. Display\n8. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 3:
                val = deleteFront();
                if (val != -1)
                    printf("Deleted from front: %d\n", val);
                break;
            case 4:
                val = deleteRear();
                if (val != -1)
                    printf("Deleted from rear: %d\n", val);
                break;
            case 5:
                val = peekFront();
                if (val != -1)
                    printf("Front element: %d\n", val);
                break;
            case 6:
                val = peekRear();
                if (val != -1)
                    printf("Rear element: %d\n", val);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
