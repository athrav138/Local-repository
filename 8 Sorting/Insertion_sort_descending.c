# include <stdio.h>

int main(){
  int n,i,j,key;

  printf("Enter the size of array:");
  scanf("%d",&n);

  int arr[n];
  int arr1[n];

  printf("Enter array element:\n");
  for( i=0;i<n;i++){
    printf("Enter %d element:",i);
    scanf("%d",&arr[i]);
  }

  printf("Array element after sorting:\n");
 
  for(i=1;i<n;i++){
    key=arr[i];
    j=i-1;
    while(j>=0 && arr[j]<key){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
  }
  for( i=0;i<n;i++){
    printf("%d ",arr[i]);
  }

  return 0;
}