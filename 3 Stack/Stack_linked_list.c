#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Global top pointer for stack
struct Node *top = NULL;

void push(int n);
void pop();
void peek();
void display();

int main() {
    int choice, num;

    while (1) {
        printf("\n1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number you want to push: ");
                scanf("%d", &num);
                push(num);
                break;

            case 2:
                pop();
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
                printf("Enter correct choice...!\n");
        }
    }

    return 0;
}

void push(int n) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    
    newnode->data = n;
    newnode->next = top;
    top = newnode;
    printf("%d pushed to stack.\n", n);
}

void pop() {
    struct Node *temp=top;
    if(top==NULL){
        printf("The stack is empty...!\n");
        }
    else{
        printf("%d is the popped element\n",temp->data);
            top=temp->next;
            free(temp);
        }
  
}

void peek() {
    if(top==NULL){
        printf("The stack is empty\n");
    }
    else{
        printf("The peek element is:%d",top->data);
    }
    
    
}

void display() {
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    struct Node *temp=top;
    if(top==NULL){
        printf("The stack is empty\n");
    }
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    
}
