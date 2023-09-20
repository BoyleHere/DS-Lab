#include<stdio.h>
void main()
{
    int n, num, i, a;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i<n; i++){
        printf("Enter value: ");
        scanf("%d", &a);
        arr[i] = a;
    }
    //binary search
    printf("Enter number to check: ");
    scanf("%d", &num);
    int m, l = 0, r = n-1;
    while(l <= r){
        m = (r+l)/2;
        if (num == arr[m]){
            printf("The number you are searching for is %d \n It's index in the array is %d", num, m);
            break;
        }
        else if(num < arr[m]){
            r = m-1;
        }
        else if(num > arr[m]){
            l = m+1;
        }
    }
}
