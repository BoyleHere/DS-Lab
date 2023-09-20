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
    // bubble sort
    int temp;

        for (i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        printf("final array is\n");
    for(i = 0; i<n; i++){
        printf("%d\t", arr[i] );
        }
}
