# include <stdio.h>

struct college{
  struct faculty{
    char name_f[50];
    char subject[50];
    float salary_f;
    int experinence_f;
  }f[10];

  struct student{
    int roll;
    char name_s[50];
    char class[50];
    float percentage;
  }s[100];

  struct employee{
    int No;
    char name_e[50];
    float salary_e;
    int experience_e;
  }e[10];
};

int main(){

  struct college c;
  int i;
  printf("Enter faculty information:\n");
  for(i=0;i<10;i++){
    printf("Enter faculty %d information:\n",i+1);
    printf("Enter name:");
    scanf("%s",c.f[i].name_f);
    printf("Enter subject:");
    scanf("%s",c.f[i].subject);
    printf("Enter salary:");
    scanf("%f",&c.f[i].salary_f);
    printf("Enter experience:");
    scanf("%d",&c.f[i].experinence_f);
  }

  printf("\n\nEnter information of students:\n");
  
  for(i=0;i<100;i++){
    printf("\nEnter %d student information:\n",i+1);
     printf("Enter name:");
    scanf("%s",c.s[i].name_s);
    printf("Enter class:");
    scanf("%s",c.s[i].class);
    printf("Enter roll no:");
    scanf("%d",&c.s[i].roll);
    printf("Enter percentage:");
    scanf("%f",&c.s[i].percentage);
  }

   printf("\n\nEnter information of employee:\n");

  for(i=0;i<10;i++){
    printf("\nEnter %d employee information:\n",i+1);
     printf("Enter name:");
    scanf("%s",c.e[i].name_e);
    printf("Enter salary:");
    scanf("%f",&c.e[i].salary_e);
    printf("Enter employee no:");
    scanf("%d",&c.e[i].No);
    printf("Enter experience:");
    scanf("%d",&c.e[i].experience_e);
  }

  printf("\n\n\nCollege Information:\n");
  printf("All Faculty information: \n");
  for(i=0;i<10;i++){
    printf("Faculty %d information:\n",i+1);
    printf("Name:%s",c.f[i].name_f);
    printf("\nSalary:%f\n",c.f[i].salary_f);
    printf("\nsubject:%s\n",c.f[i].subject);
    printf("\nExperience:%d\n",c.f[i].experinence_f);
  }

  printf("All Students information: \n");
  for(i=0;i<100;i++){
    printf("Studnets %d information:\n",i+1);
    printf("Name:%s",c.s[i].name_s);
    printf("\nClass:%s\n",c.s[i].class);
    printf("\nRoll:%d\n",c.s[i].roll);
    printf("\nPercentage:%f\n",c.s[i].percentage);
  }

  printf("All Employee information: \n");
  for(i=0;i<10;i++){
    printf("Employee %d information:\n",i+1);
    printf("Name:%s",c.e[i].name_e);
    printf("\nSalary:%f\n",c.e[i].salary_e);
    printf("\nExperience:%d\n",c.e[i].experience_e);
    printf("\nEmployee No:%d\n",c.e[i].No);
  }
  
  return 0;
}