# include <stdio.h>
# include <stdlib.h>

struct node {
  char data[10];
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
    printf("Enter data %d:",i+1);
    scanf("%s",new->data);
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
  
  tem=head;
  while(tem!=NULL){
      printf("%s -> ",tem->data);
     tem=tem->next;
  }
  
  return 0;
}

