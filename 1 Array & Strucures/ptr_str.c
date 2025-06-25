# include <stdio.h>

struct pointer{
  int a;
  float b;
  char ch;
  char str[10];
  double z;
};

int main(){
    struct pointer p;
struct pointer *ptr=&p;
printf("Enter num:");
scanf("%d",&ptr->a);
printf("Enter decimal:");
scanf("%f",&ptr->b);
printf("Enter character:");
scanf(" %c",&ptr->ch);
printf("Enter string:");
scanf("%s",&ptr->str);
printf("Enter double:");
scanf("%lf",&ptr->z);


printf("Entered information:\n");
printf("Integer:%d\n",ptr->a);
printf("Decimal:%f\n",ptr->b);
printf("Character:%c\n",ptr->ch);
printf("String:%s\n",ptr->str);
printf("Double:%lf",ptr->z);

  return 0;
}