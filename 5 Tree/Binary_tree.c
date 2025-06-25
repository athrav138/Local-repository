# include <stdio.h>
# include <stdlib.h>

struct tree{
  int data;
  struct tree *left;
  struct tree *right;
};

struct tree *createnode(int data);

int main(){
  struct tree *p=(struct tree*)malloc(sizeof(struct tree));
  p->data=10;
  p->left=NULL;
  p->right=NULL;

  struct tree *p1=(struct tree*)malloc(sizeof(struct tree));
  p1->data=15;
  p1->left=NULL;
  p1->right=NULL;

  struct tree *p2=(struct tree*)malloc(sizeof(struct tree));
    p2->data=20;

  p2->left=NULL;
  p2->right=NULL;

  p->left=p1;
  p->right=p2;

printf("%d %d %d ",p->data,p1->data,p2->data);
  return 0;
}

struct tree *createnode(int data){
  struct tree *n=(struct tree*)malloc(sizeof(struct tree ));
  n->data=data;
  n->left=NULL;
  n->right=NULL;
  return n;
}