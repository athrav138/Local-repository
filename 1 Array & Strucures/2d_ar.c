# include <stdio.h>

int main(){
 int ar[2][3]={{1,2,3},
               {4,5,6}};
  
  int arr[3][2];
  for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
      printf("Enter arr[%d][%d]:",i,j);
      scanf("%d",&arr[i][j]);
    }
  }
  printf("\n\narr=\n");
  for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
  printf("\nar=\n");
  for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
      printf("%d ",ar[i][j]);
    }
    printf("\n");
  }

  return 0;
}