# include <stdio.h>

int main(){
    int r,c,index,total;
    printf("Entner rows and columns:");
    scanf("%d %d",&r,&c);
    int arr[r][c];
    index=0;
    total=r*c;
    int ar[total];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("Enter arr[%d][%d]:",i,j);
            scanf("%d",&arr[i][j]);
            ar[index++]=arr[i][j];
        }
    }

     for(int i=0;i<total-1;i++){
    for(int j=0;j<total-1-i;j++){
      if(ar[j]<ar[j+1]){
        int temp=ar[j];
        ar[j]=ar[j+1];
        ar[j+1]=temp;
      }
    }
  }
index=0;
  for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
           
            arr[i][j]=ar[index++];
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
           
            printf("%d ",arr[i][j]);
        }
    }

    return 0;
}