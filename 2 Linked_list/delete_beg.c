# include <stdio.h>
# include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};


int main(){
  struct Node *newnode=NULL;
  struct Node *head=NULL;
  struct Node *temp=NULL;

  int n;
  printf("Enter Size:");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    newnode=(struct Node *)malloc(sizeof(struct Node));

    printf("%d.Enter value:",i+1);
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

  if (head == NULL) {
        printf("List is already empty.\n");
    } else {
       temp=head;
       head=head->next;
       printf("THe deleted data is %d\n",temp->data);
       free(temp);
    }

  temp=head;
  printf("The data in linked list is after deletition of bigining:\n");
  while(temp!=NULL){
    printf("%d -> ",temp->data);
    temp=temp->next;
  }
  printf("NULL");
    return 0;
}