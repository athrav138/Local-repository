# include <stdio.h>

int main(){
  int n,pos,new;
  printf("Enter n:");
  scanf("%d",&n);
  int arr[n];
  for(int i=0;i<n;i++){
    printf("enter arr[%d]:",i);
    scanf("%d",&arr[i]);
  }

  printf("Enter the position from 0 to %d at which you want insert new value fr:",n);
  scanf("%d",&pos);
  printf("Enter new value:");
  scanf("%d",&new);

  arr[pos-1]=new;
  printf("New inserted array:\n");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }


  return 0;
}