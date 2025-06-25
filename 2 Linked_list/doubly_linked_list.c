# include <stdio.h>
# include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
    struct NODE *pre;
};

int main(){
    struct NODE *head=NULL,*newnode=NULL,*temp=NULL;
    
    int n;
    printf("Enter size of a doubly linked list:");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        newnode=(struct NODE *)malloc(sizeof(struct NODE));
        printf("%d.Enter element:",i+1);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->pre=NULL;
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next = newnode;
            newnode->pre = temp;
            temp = newnode;
          }
        }

 temp=head;
 printf("Doubly linked list elements: ");
 while(temp!=NULL){
     printf("%d <-> ",temp->data);
     temp=temp->next;
 }
 printf(" NULL");
 
 return 0;
}