# include <stdio.h>

int main(){
  int size,i;

  printf("Enter the size of array:");
  scanf("%d",&size);

  int arr[size];

  printf("Enter array element:\n");
  for( i=0;i<size;i++){
    printf("Enter %d element:",i);
    scanf("%d",&arr[i]);
  }

  printf("Array element after sorting:\n");
  for( i=0;i<size;i++){
      for(int j=0;j<size-i-1;j++){
          if(arr[j]<arr[j+1]){
              int temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
          }
      }
  }
  
  for( i=0;i<size;i++){
    printf("%d ",arr[i]);
  }

  return 0;
}