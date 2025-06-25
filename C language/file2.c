# include <stdio.h>

int main(){
  FILE *fptr;
  fptr=fopen("file1.txt","a");
  char ch;
  fprintf(fptr,"%s","hello world ");
  fclose(fptr);
  


  return 0;
}