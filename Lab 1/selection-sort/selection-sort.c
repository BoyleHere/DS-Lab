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
    int smallest, temp, j;
    for (i = 0; i<n; i++){
        for (int j = 0; j < n; j++) {
                if (arr[j] > arr[j + 1]) {
                        smallest = arr[j];

                }
        }
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
    }
            printf("final array is\n");
    for(i = 0; i<n; i++){
        printf("%d\t", arr[i] );
        }
}
