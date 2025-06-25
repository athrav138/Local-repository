# include <stdio.h>
# include <stdlib.h>

int main(){
int *ptr;

ptr=(int *)calloc(5,sizeof(int));
for(int i=0;i<5;i++){
  printf("ptr[%d]:",i);
  scanf("%d",&ptr[i]);
}

ptr=(int *)realloc(ptr,8*sizeof(int ));
for(int i=5;i<8;i++){
  printf("ptr[%d]:",i);
  scanf("%d",&ptr[i]);
}

for(int i=0;i<8;i++){
  printf("%d ",ptr[i]);
}
  return 0;
}