#include <stdio.h>
#include <conio.h>
#define MAXSIZE10

int stack[MAXSIZE];
int top = -1;

int main() {
   int choice();
   clrscr();
   
   do {
       printf("\n1. push\n2. pop\n3. Display\n4. Exit\n");
       printf("Enter your choice:");
       scanf("%d", &choice);
       switch(choice){
           case 1:
            push(); break;
           case 2:
           pop(); break;
           case 3:
           display();  break;
       }
   }
   while (choice!=4);
   getch();
}
push(){
    int n;
    if(top == MAXSIZE-1){
        printf("stack overflow\n");//check if the stack is full (overflow condition)
    }
    else{
        printf("enter an element");
        scanf("%d",&n);
        top++;
        //increment the top  index and add the element
        stack[top] = n;
    }
}
pop{
    int n;
    if(top == -1){
        printf("stack Underflow\n"); //check if the stackis empty(underflow condition)
    }
    else{
        n = stack[top];
        top--; // remove and return the top element
        printf("popped element is %d", n);
    }
}
void display(){
   if(top == -1)
      printf("\nStack is Empty!!!");
   else{
      int i;
      printf("\nStack elements are:\n");
      for(i=top; i>=0; i--)
	 printf("%d\n",stack[i]);
   }
}
