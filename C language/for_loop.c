# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main(){

  for(int i=0;i<10;i++){
    printf("Rucha!\n");
  }
  int *ptr;
  ptr=(int*)malloc(10*sizeof(int));
  ptr[0]=5;
  printf("%d",ptr[2]);

  return 0;
}