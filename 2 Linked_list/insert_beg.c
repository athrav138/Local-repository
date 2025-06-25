# include <stdio.h>
# include <stdlib.h>

struct NODE {
  int data;
  struct NODE *next;
};

void insertat_beg(struct NODE **head,int element);

int main(){
  struct NODE *head=NULL;
  struct NODE *newnode=NULL;
  struct NODE *temp=NULL;
  int n;
  printf("ENter size:");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    newnode=(struct NODE *)malloc(sizeof(struct NODE));

    printf("Enter element %d:",i+1);
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
  }

  int element;
  printf("Enter elements that is to insert at begining:");
  scanf("%d",&element);

 insertat_beg(&head,element);

  printf("THe data of linked list:\n");
  temp=head;
  while(temp!=NULL){
    printf("%d -> ",temp->data);
    temp=temp->next;
  }

  return 0;
}

void insertat_beg(struct NODE **head,int element){
    struct NODE *newnode = (struct NODE *)malloc(sizeof(struct NODE));
    newnode->data=element;
    newnode->next=*head;
    *head=newnode;
}


