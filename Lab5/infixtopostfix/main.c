#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#define MAX_SIZE 100

int precedence(char operator)
{
    switch(operator)
    {
        case'+':
        case'-':
        return 1;

        case'*':
        case'/':
        return 2;

        case'^':
        return 3;

        default:
        return -1;

    }
}
int IsOperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        return 1;
        return 0;
}

char* convert(char infix[])
{char stack[MAX_SIZE];
    int len= strlen(infix);
    char* postfix=(char*)malloc(sizeof(char)*(len+2));
    int top=-1;
    int i=0,j=0;

    for(i=0,j=0; i<len ; i++)
    {
        if(infix[i]==" "||infix[i]=='\t')
            continue;
        if(isalnum(infix[i]))
        {
            postfix[j++]=infix[i];
        }
        else if(infix[i]=='(')
        {
            stack[++top]==infix[i];
        }
        else if(infix[i]==')')
        {
            while(top>-1&&stack[top]!='(')
                    postfix[j++]=stack[top--];
            top--;
        }
        else if(IsOperator(infix[i]))
        {
            while(top>-1&&precedence(stack[top])>precedence(infix[i]))
                    postfix[j++]=stack[top--];
                    stack[++top]=infix[i];
        }
    }
   while(top>-1)
   {
       if(stack[top]=='(')
       {
           return "Invalid expression";
       }
        postfix[j++]=stack[top--];
   }
    postfix[j]=='\0';
    return postfix;
}

  int main()
  {
      char infix[MAX_SIZE]="a+b*(c^d-e)^(f+g*h)-i";
      char* postfix=convert(infix);
      printf("%s\n",postfix);
      free(postfix);
      return 0;
  }
