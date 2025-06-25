# include <stdio.h>

int main(){
int row,column,r,c,new;
printf("Enter row:");
scanf("%d",&row);
printf("Enter column:");
scanf("%d",&column);
int arr[row][column];
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      printf("Enter arr[%d][%d]:",i,j);
      scanf("%d",&arr[i][j]);
    }}

    printf("Enter the position from arr[0][0] to arr[%d][%d] at which you want insert new value :",row,column);
  scanf("%d",&r);
  printf("Enter col:");
  scanf("%d",&c);
  printf("Enter new value:");
  scanf("%d",&new);
  arr[r][c]=new;
  printf("New inserted array:\n");
   printf("\n\narr=\n");
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }


  return 0;
}