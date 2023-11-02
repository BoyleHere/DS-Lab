#include<stdio.h>
#include<string.h>

struct stack{
    char arr[100];
    int top;
    };
    struct stack s;


void push(char a)
{
    if(s.top==99)
        printf("stack overflow");
    else
    {
        s.top++;
        s.arr[s.top]=a;
    }
}

char pop()
{
    char ele;
    if(s.top==-1)
        printf("stack underflow");
    else
    {
        ele=s.arr[s.top];
        s.top--;
        return ele;
    }
}

int main()
{
    int i,len,flag=1;
    char str[50], a;

    printf("enter expression");
    gets(str);
    len=strlen(str);

    for(i=0;i<len;i++)
    {
        if(str[i]== '(' || str[i]== '{' || str[i]== '[')
            {
                push(str[i]);
            }


        else if (str[i]== ')' || str[i]== '}' || str[i]== ']' )
            {
                a=pop();
                if((str[i]== ')' && a!='(') || (str[i]== '}'  && a!='{') || (str[i]== ']' && a!='['))
                    flag=0;
            }
    }

    if (flag)
        printf("expression is correct");
    else
        printf("expression is wrong");
}
