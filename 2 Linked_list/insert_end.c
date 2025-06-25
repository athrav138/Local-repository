#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
};

void insertat_end(struct NODE **head, int element);

int main() {
    struct NODE *head = NULL;
    struct NODE *temp = NULL;
    struct NODE *newnode = NULL;

    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newnode = (struct NODE *)malloc(sizeof(struct NODE));
        printf("%d. Enter value: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    int element;
    printf("Enter element to insert at end: ");
    scanf("%d", &element);

    insertat_end(&head, element);

    printf("Linked list after insertion:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}



void insert_end(struct NODE **head, int element)
{
    struct NODE *newnode=NULL;
    newnode=(struct NODE *)malloc(sizeof(struct NODE *));
    newnode->data=element;
    newnode->next=NULL;

    if(*head==NULL){
        *head=newnode;
    }
    else{
        struct NODE *temp=NULL;
        temp=*head;
        while(temp!=NULL){
            temp=temp->next;
        }
            temp->next=newnode;

    }

}
