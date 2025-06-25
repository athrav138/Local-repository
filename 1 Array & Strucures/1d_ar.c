# include <stdio.h>

int main(){
  int ar[]={2,3,4,5,6};

  int arr[10];
  for(int i=0;i<10;i++){
    printf("Enter arr[%d]:",i);
    scanf("%d",&arr[i]);
  }
  printf("arr =");
  for(int i=0;i<10;i++){
    printf("%d ",arr[i]);
  }
  printf("\nar = ");
  for(int i=0;i<5;i++){
    printf("%d ",ar[i]);
  }
 
  return 0;
}