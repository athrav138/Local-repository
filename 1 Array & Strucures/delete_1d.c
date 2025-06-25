# include <stdio.h>

int main(){
    int n,del;
    printf("Enter Size of array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("enter arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    printf("Enter the position to delete(0 to %d):",n);
    scanf("%d",&del);
    for(int i=del-1;i<n;i++){
        arr[del-1]=arr[del];
        del++;
    }
    
    for(int i=0;i<n-1;i++){
        printf("%d ",arr[i]);
        
    }
    
    
    return 0;
}