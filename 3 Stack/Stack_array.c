# include <stdio.h>
# include <stdlib.h>

# define N 5

int stack[N];
int top=-1;


void push(int num);
void pop();
void peek();
void display();


int main(){
 int choice,num;
 
 while(1){
    printf("\n1. PUSH.\n2. POP.\n3. PEEK.\n4. DISPLAY.\n5. EXIT.\n");
    
    printf("Enter your choice:");
    scanf("%d",&choice);
 switch(choice){
     case 1:
     printf("Enter number your want to push:");
     scanf("%d",&num);
     push(num);
     break;
     
     case 2: 
     pop();
     break;
     
     case 3:
     peek();
     break;
     
     case 4: 
     display();
     break;
     
     case 5:
     return 0;

     default:
     printf("Enter correct choice.....!\n");
     break;
    }
 }
}

void push(int num){
    
    if(top==N-1){
        printf("The stack is overflow....!\n");
    }
    else{
        top++;
        stack[top]=num;
        printf("The %d is pushed in stack on %d position.\n",num,top);
    }
}

void pop(){
    if(top==-1){
        printf("The stack is empty......!\n");
    }
    else{
        int n=stack[top];
        top--;
        printf("The popped element is:%d\n",n);
    }
}
void peek(){
    int n;
    if(top==-1){
    printf("The stack is empty....!\n");
    }
    else{
        n=stack[top];
        printf("The peek element in the stack is %d.\n",n);
    }
    
}
void display(){
    if(top==-1){
        printf("The stack is empty....!\n");
    }
    else{
    printf("The stack is:\n");
    for(int i=0;i<=top;i++){
        printf("%d -> ",stack[i]);
    }
   }
}
