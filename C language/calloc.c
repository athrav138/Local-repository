# include <stdio.h>
# include <stdlib.h>

int main(){
  int *ptr;
  int n;
  printf("Enter n:");
  scanf("%d",&n);
  ptr=(int *)calloc(n,sizeof(int));
  printf("%d",ptr[3]);
    free(ptr);

    ptr=(int *)calloc(2,sizeof(int));

  for(int i=0;i<2;i++){
    scanf("%d",&ptr[i]);
  }
  for(int i=0;i<n;i++){
    printf("%d ",ptr[i]);
  }
  free(ptr);


  return 0;
}