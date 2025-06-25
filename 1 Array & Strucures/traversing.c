# include <stdio.h>

int main(){
  int n;
  printf("Enter size of array:");
  scanf("%d",&n);

  int ar[n];

  for(int i=0;i<n;i++){
    printf("Enter ar[%d]:",i);
    scanf("%d",&ar[i]);
  }
  printf("The 1D array elements are:\n");
  for(int i=0;i<n;i++){
    printf("%d  ",ar[i]);
  }
  printf("\n\n\n");
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
printf("The 2D array elements are:\n");
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      printf("%d  ",arr[i][j]); 
    }
    printf("\n");
  }


  return 0;
}