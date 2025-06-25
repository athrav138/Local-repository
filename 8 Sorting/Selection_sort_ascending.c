# include <stdio.h>

int main(){
  int n,i,j,key;

  printf("Enter the size of array:");
  scanf("%d",&n);

  int arr[n];

  printf("Enter array element:\n");
  for( i=0;i<n;i++){
    printf("Enter %d element:",i);
    scanf("%d",&arr[i]);
  }

 
  for(i=0;i<n;i++){
    int min=i;
    for(int j=i+1;j<n;j++){
        
      if(arr[min]>arr[j]){
          
      int temp=arr[min];
      arr[min]=arr[j];
      arr[j]=temp;
      
     }
    }
  }
  
    printf("Array element after sorting:\n");
  for( i=0;i<n;i++){
    printf("%d ",arr[i]);
  }

  return 0;
}