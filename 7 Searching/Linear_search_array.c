# include <stdio.h>

int main(){
    int n,i,num,count=0;
    printf("Enter the size of array you want to declare.\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d  elements of array:\n",n);
    for(i=0;i<n;i++){
        printf("Enter element %d:",i);
        scanf("%d",&arr[i]);
    }
    
    printf("Entered array:\n");
     for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
    printf("\nEnter element you want to search in array:");
    scanf("%d",&num);
    
    for(i=0;i<n;i++){
        if(arr[i]==num){
            printf("%d is the element found in %d position\n",num,i);
            count++;
        }
    }
    
    if(count==0){
        printf("%d is the element not found in array.\n");
    }

    
    return 0;
}