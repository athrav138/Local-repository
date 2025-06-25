# include <stdio.h>

int main(){
FILE *fptr;
fptr=fopen("floop.txt","r");
char ch=fgetc(fptr);
while(ch!=EOF){
  printf("%c",ch);
  ch=getc(fptr);
}







fclose(fptr);

  return 0;
}