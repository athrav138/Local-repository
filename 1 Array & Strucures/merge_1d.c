# include <stdio.h>

int main(){
    int n1,n2;
    printf("Enter size of array1:");
    scanf("%d",&n1);
    printf("Enter size of array2:");
    scanf("%d",&n2);
    int arr1[n1],arr2[n2],merge[100];
    printf("Enter Elements for array 1:\n");
    for(int i=0;i<n1;i++){
        printf("Enter arr[%d]:",i);
        scanf("%d",&arr1[i]);
    }
    
    printf("Enter Elements for array 2:\n");
    for(int i=0;i<n2;i++){
        printf("Enter arr[%d]:",i);
        scanf("%d",&arr2[i]);
    }
    
    for(int i=0;i<n1;i++){
        merge[i]=arr1[i];
    }
    
    for(int i=0;i<n2;i++){
        merge[n1+i]=arr2[i];
    }
    printf("Merging of two array 1d:\n");
    for(int i=0;i<n1+n2;i++){
       printf("%d ",merge[i]);
    }
    
    return  0;
}