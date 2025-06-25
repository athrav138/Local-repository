# include <stdio.h>
# include <stdlib.h>

struct NODE {
  int data;
  struct Node *next;
};

int main(){
  struct NODE* head=NULL;
  head =(struct NODE*)malloc(sizeof(struct NODE));
  head->data=10;
  head->next=NULL;
  printf("The value of First NODE is :%d",head->data);
  return 0;
}