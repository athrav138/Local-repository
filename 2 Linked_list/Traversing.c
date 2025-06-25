# include <stdio.h>
# include <stdlib.h>

struct node {
  int data;
  char daa[10];
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
    printf("Enter name :",i+1);
    scanf("%s",new->daa);
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
    printf("%d. %s -> ",tem->data,tem->daa);
    tem=tem->next;
  }

  
  
  return 0;
}

