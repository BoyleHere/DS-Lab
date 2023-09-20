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
    //insertion sort
    int key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1],
           that are greater than key,
           to one position ahead of
           their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("final array is\n");
    for(i = 0; i<n; i++){
        printf("%d\t", arr[i] );
        }
}
