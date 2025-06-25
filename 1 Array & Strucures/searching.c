# include <stdio.h>

int main(){
  int n,num,count=0;
  printf("Enter size of array:");
  scanf("%d",&n);

  int ar[n];

  for(int i=0;i<n;i++){
    printf("Enter ar[%d]:",i);
    scanf("%d",&ar[i]);
  }

  printf("Enter number you want to search:");
  scanf("%d",&num);

  for(int i=0;i<n;i++){
    if(ar[i]==num){
      printf("The %d is number found on ar[%d] index number \n",num,i);
      count++;
    }
  }

  int row,column;
  printf("Enter Row:");
  scanf("%d",&row);
    printf("Enter Column:");
    scanf("%d",&column);


  int arr[row][column];

  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      printf("Enter arr[%d][%d]:",i,j);
      scanf("%d",&arr[i][j]);
    }
  }

 for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      if(arr[i][j]==num){
        printf("The %d is number is found on  arr[%d][%d] index number\n",num,i,j);
        count++;
      }
    }
  } 
  
  if(count==0){
      printf("The %d number is not found in the both array",num);
  }
  


  return 0;
}