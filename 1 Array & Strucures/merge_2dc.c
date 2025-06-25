# include <stdio.h>

int main(){
    int r1,c1,r2,c2;

    printf("Enter row:");
    scanf("%d",&r1);
    printf("Enter column:");
    scanf("%d",&c1);

    int arr1[r1][c1];

    printf("Enter elements of array 1:\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            printf("Enter arr1[%d][%d]:",i,j);
            scanf("%d",&arr1[i][j]);
        }
    }
    
    printf("Enter row:");
    scanf("%d",&r2);
    printf("Enter column:");
    scanf("%d",&c2);
int arr2[r2][c2];
 int merge[r1][c1+c2];
    if(r1==r2){

    printf("Enter elements of array 2:\n");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            printf("Enter arr2[%d][%d]:",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }
    for(int i=0;i<r1;i++ ){
        for(int j=0;j<c1;j++){
            merge[i][j]=arr1[i][j];
        }
    }
    for(int i=0;i<r2;i++ ){
        for(int j=0;j<c2;j++){
            merge[i][j+c1]=arr2[i][j];
        }
    }

    for(int i=0;i<r1;i++){
        for(int j=0;j<c1+c2;j++){
            printf("%d ",merge[i][j]);
        }
        printf("\n");
    }

    }
    else{
        printf("The merging of the given array is not possible");
    }

    return 0;
}