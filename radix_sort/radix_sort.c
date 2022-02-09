#include <stdio.h>

void RadixSort(int *arr, int len)
{
}

int main()
{
    int arr[] = {1, 3, 2, 5, 8, 3, 9, 4};
    RadixSort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}