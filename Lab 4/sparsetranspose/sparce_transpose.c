#include<stdio.h>

struct sparce{
    int row;
    int col;
    int val;
};

struct sparce s1[10], s2[10];

void transpose(){
    s2[0].row=s1[0].col;
    s2[0].col=s1[0].row;
    s2[0].val=s1[0].val;
    int t=0;
    for(int i=0;i<s1[0].col;i++){
        for(int j=1;j<=s2[0].val;j++){
            if(s1[j].col==i){
            t++;
            s2[t].row=s1[j].col;
            s2[t].col=s1[j].row;
            s2[t].val=s1[j].val;
            }
        }
    }

}

void display(struct sparce a[10]){
    for(int i=0; i<=a[0].val; i++)
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].val);
    printf("\n \n");
}


int main(){
    int m,n,i,j,k=0;
    int ele;
    printf("enter dimensions ");
    scanf("%d %d", &n, &m);

    s1[0].row=n;
    s1[0].col=m;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("input element");
            scanf("%d", &ele);
            if (ele!=0){
                k++;
                s1[k].row=i;
                s1[k].col=j;
                s1[k].val=ele;
            }
            else
                continue;
        }
    }

    s1[0].val=k;

    transpose();
    display(s1);
    display(s2);




}

