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
    //linear search
    printf("Enter number to check: ");
    scanf("%d", &num);
    for(i = 0; i<n; i++){
        if(num == arr[i]){
            printf("The number you are searching for is %d \nIt's index in the array is %d", num, i );
            break;
        }

    }

}
