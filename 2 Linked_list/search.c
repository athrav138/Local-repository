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
int key;
printf("Enter the element you want to find:");
scanf("%d",&key);
int pos=1,count=0;
  tem=head;
  while(tem!=NULL){
    if(tem->data==key){
      printf("%d is the element found on %d position\n",key,pos);
      count++;

    }
    tem=tem->next;
    pos++;
  }
  
  if(count==0){
      printf("The element is not found in the liked  list");
  }

  
  
  return 0;
}

