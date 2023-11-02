#include<stdio.h>
int lengthof(char a[])
{
    int j;
    for(j=0;a[j]!='\0';j++);
    printf("the length of the string is %d\n",j);
    return j;
}
int concate(char x[],char y[])
{
    int i,a,b,j;
    for(i=0;x[i]!=0;i++);
    a=i;
    for(j=0;y[j]!=0;j++);
    b=j;
    j=0;
    for(i=a;i<a+b;i++,j++)
    {
        x[i]=y[j];

    }
    printf("the concatenated string is %s\n",x);
}
int compare(char g[],char h[])
{

}
int ins(char s1[],char s2[],int pos)
{
    int i,a,b,j;
    for(i=0;s1[i]!='\0';i++);
    for(j=0;s2[j]='\0';j++);
    printf("%d%d",i,j);
    a=i;
    b=j;
    j=0;
    for(i=a;i>=pos;i--)
        s1[i+b]=s1[i];
    for(i=pos;i<pos+b;i++,j++)
        s1[i]=s2[j];
    printf("the string after insertion is %s\n",s1);
}
int main ()
{   int n = 1;
    while(n == 1){
        int a,n,i;
        char b[100];
        char c[100],d[100];
        printf("enter what operation you want to perform:\n");
        printf("1. find length of string\n");
        printf("2. string concatenation\n");
        printf("3. string comparison\n");
        printf("4. insert a substring\n");
        printf("5. delete a substing\n");
        printf("6. exit\n");
        scanf("%d",&a);
        if (a==1)
        {
            printf("enter the string: ");
            scanf("%s",b);
            lengthof(b);
        }
        if (a==2)
        {
            printf("enter the first string: ");
            scanf("%s",&c);
            printf("enter the second string: ");
            scanf("%s",&d);
            concate(c,d);
        }
        if (a==4)
        {
            printf("enter the first string: ");
            scanf("%s",&c);
            printf("enter the string to be inserted: ");
            scanf("%s",&d);
            printf("enter the position: ");
            scanf("%d",&n);
            ins(c,d,n);
        }
        if (a == 6){
            n = 0;
            }
        }
    }

