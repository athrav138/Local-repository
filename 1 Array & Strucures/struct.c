# include <stdio.h>

struct structure{
 int n;
 char name[50];
 float value;
};

struct structure2{
  int a;
  char string[50];
  float deci;
}s[5];

int main(){
  struct structure s1={2,"hello",2.3};
  printf("Integer 1=%d\n",s1.n);
  printf("String 1=%s\n",s1.name);
  printf("Decimal 1=%f",s1.value);

  struct structure s2;
  printf("\nEnter integr:");
  scanf("%d",&s2.n);
  printf("Enter string:");
  scanf("%s",s2.name);
  printf("Enter decimal:");
  scanf("%d",&s2.value);

  printf("Integer 2=%d\n",s2.n);
  printf("String 2=%s\n",s2.name);
  printf("Decimal 2=%f",s2.value);

  for(int i=0;i<5;i++){
    printf("\nEnter information of %d ",i+1);
    printf("\nEnter number:");
    scanf("%d",&s[i].a);
    printf("Enter string:");
    scanf("%s",&s[i].string);
    printf("Enter decimal:");
    scanf("%f",&s[i].deci);
  }

  for(int j=0;j<5;j++){
  printf("The information of %d\n",j+1);
  printf("Integer =%d\n",s[j].a);
  printf("String =%s\n",s[j].string);
  printf("Decimal =%f\n",s[j].deci);


  }
  return 0;
}