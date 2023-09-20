#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
char s[MAX_SIZE];
    int top=-1;
void push(char c)
{
    if(top>=MAX_SIZE-1)
    {
        printf("stack overflow");
        return;
    }
    top++;
    s[top]=c;
}
int pop()
{
    if(top<0)
    {
        printf("stack underflow");
        return -1;
    }
    int c=s[top];
    top--;
    return c;
}
int IsOperand(char x)
{
    if((x>='a'&&x<='z')||(x>='A'&&x<='Z'))
        return 1;
        return 0;
}
char* convert(char exp[])
{
    char op;
    char s[MAX_SIZE];
    int top=-1;
    for(int i=0;exp[i]!='\0';i++)
    {
        if(IsOperand(exp[i]))
        {
           push(op);
        }
        else
        {
          char op1=s[top];
          pop();
          char op2=s[top];
          pop();
          push('('+op2+exp[i]+op1+')');
        }
    }
    return s[top];
}
int main()
  {
      char exp[MAX_SIZE];
      printf("enter a postfix expression");
      scanf("%s",exp);
     int result=convert(exp);
      printf("result=%s\n",result);
      return 0;
  }
