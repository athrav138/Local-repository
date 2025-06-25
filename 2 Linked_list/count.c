# include <stdio.h>
# include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

int main(){
  struct node *new=NULL;
  struct node *tem=NULL;
  struct node *head=NULL;

  int n;
  printf("Enter n:");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    new=(struct node*)malloc(sizeof(struct node));
    printf("%d.Enter data:",i+1);
    scanf("%d",&new->data);
   
    new->next=NULL;
    if(head==NULL){
      head=new;
      tem=head;
    }
    else{
      tem->next=new;
      tem=new;
    }
  }

int count=0;
  tem=head;
  while(tem!=NULL){
  count++;
    tem=tem->next;
  }
  
  if(count==0){
      printf("The liked list is empty\n");
  }
  else{
    printf("The linked list have %d elements.\n",count);
  }

  
  
  return 0;
}

