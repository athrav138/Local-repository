#include <stdio.h>
#define MAX 100

typedef struct {
    int data;
    int priority;
} Element;

Element pq[MAX];
int size = 0;

// Insert function
void insert(int value, int priority) {
    if (size == MAX) {
        printf("Priority Queue Overflow\n");
        return;
    }

    int i = size - 1;

    // Move elements with lower priority
    while (i >= 0 && pq[i].priority > priority) {
        pq[i + 1] = pq[i];
        i--;
    }

    // Insert the new element
    pq[i + 1].data = value;
    pq[i + 1].priority = priority;
    size++;

    printf("Inserted: %d with priority %d\n", value, priority);
}

// Delete (dequeue) function
void delete() {
    if (size == 0) {
        printf("Priority Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d with priority %d\n", pq[0].data, pq[0].priority);

    // Shift all elements to left
    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Display function
void display() {
    if (size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue contents:\n");
    for (int i = 0; i < size; i++) {
        printf("Value: %d  Priority: %d\n", pq[i].data, pq[i].priority);
    }
}

// Main function
int main() {
    int choice, val, prio;

    while (1) {
        printf("\n1. Insert\n2. Delete (Dequeue)\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d %d", &val, &prio);
                insert(val, prio);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
