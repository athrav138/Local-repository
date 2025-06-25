# include <stdio.h>

int main(){
  FILE *fptr;
  fptr=fopen("odd.txt","w");
  int n;
  printf("Enter n:");
  scanf("%d",&n);
  for(int i=1;i<=n;i=i+2){
    fprintf(fptr,"%d ",i);

  
  }
  
  fclose(fptr);


  return 0;
}