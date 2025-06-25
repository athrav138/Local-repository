# include <stdio.h>
# include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
};

int main(){
    struct NODE *head=NULL,*newnode=NULL,*temp=NULL;
    
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        newnode=(struct NODE *)malloc(sizeof(struct NODE));
        
        printf("%d.Enter linked list data: ",i+1);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=head;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        temp->next=head;
    }
    
    temp=head;
    while(temp->next!=head){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
            printf("%d -> ",temp->data);

    printf("NULL");
}