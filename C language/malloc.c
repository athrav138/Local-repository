# include <stdio.h>
# include <stdlib.h>

int main(){
int *ptr;
int n;
printf("Enter n:");
scanf("%d",&n);
ptr=(int* )malloc(n*sizeof(int));
printf("%d",ptr[4]);
free(ptr);
ptr=(int* )malloc(2*sizeof(int));

for(int i=0;i<2;i++){
  scanf("%d",&ptr[i]);
}
for(int i=0;i<2;i++){
  printf("%d ",ptr[i]);
}
free(ptr);


  return 0;
}