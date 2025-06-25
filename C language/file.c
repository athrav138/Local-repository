# include <stdio.h>

int main(){
  FILE *fptr;
  fptr=fopen("file1.txt","a");
  char str;

  if(fptr==NULL){
    printf("File doesn't exits ");
  }
else{
  fprintf(fptr,"%s","hello world to all");
}
fscanf(fptr,"%c",str);
fclose(fptr);
putchar(str);

  return 0;
}