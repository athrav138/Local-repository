# include <stdio.h>

int main(){
int row,column,r,c;
printf("enter row:");
scanf("%d",&row);
printf("Enter column:");
scanf("%d",&column);
  int arr[row][column];
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      printf("Enter arr[%d][%d]:",i,j);
      scanf("%d",&arr[i][j]);
    }
  }
  
  printf("enter position of row:");
scanf("%d",&r);
  printf("enter position of column:");
scanf("%d",&c);
arr[r][c]=0;
  
  
  
  for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}