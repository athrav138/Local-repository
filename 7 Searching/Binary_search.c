# include <stdio.h>

int main(){
  int start=0,size,i,mid,ele;

  printf("Enter the size of array:");
  scanf("%d",&size);

  int arr[size];

  printf("Enter array element:\n");
  for( i=start;i<size;i++){
    printf("Enter %d element:",i);
    scanf("%d",&arr[i]);
  }

  printf("Array element after sorting:\n");
  for( i=start;i<size;i++){
      for(int j=0;j<size-i-1;j++){
          if(arr[j]>arr[j+1]){
              int temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
          }
      }
  }
  
  for( i=start;i<size;i++){
    printf("%d ",arr[i]);
  }

  printf("\nEnter element you want to search:");
  scanf("%d",&ele);
int end=size-1;
 start=0;
int found=0;
  while(start<=end){
        mid=start+(end-start)/2;
    if(ele>arr[mid]){
      start=mid+1;
    }
    else if(ele<arr[mid]){
      end=mid-1;
    }
    else{
      printf("%d is the number is found on %d index.\n",ele,mid);
      found=1;
      break;
    }
  }
  
  if(found==0){
      printf("%d is the element is not found.\n",ele);
  }
  return 0;
}