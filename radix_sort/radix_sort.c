#include <stdio.h>
#include <stdlib.h>

int MaxBit(int *arr, int len)
{
    int maxItem = arr[0];
    int d = 1;
    for (int i = 1; i < len; i++)
    {
        if (arr[i] > maxItem)
            maxItem = arr[i];
    }
    while (maxItem >= 10)
    {
        maxItem /= 10;
        ++d;
    }
    return d;
}

void RadixSort(int *arr, int len)
{
    int d = MaxBit(arr, len);
    int *count = (int *)malloc(10 * sizeof(int));
    int *bucketCount = (int *)malloc(len * sizeof(int));
    int k, radix = 1;
    for (int i = 0; i < d; i++)
    {

        for (int j = 0; j < 10; j++)
            count[j] = 0;

        for (int j = 0; j < len; j++)
        {
            k = (arr[j] / radix) % 10;
            count[k]++;
        }

        for (int j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j];

        for (int j = len - 1; j >= 0; j--)
        {
            k = (arr[j] / radix) % 10;
            bucketCount[count[k] - 1] = arr[j];
            count[k]--;
        }
        for (int j = 0; j < len; j++)
            arr[j] = bucketCount[j];
        radix *= 10;
    }
    free(count);
    free(bucketCount);
}

int main()
{
    // int arr[] = {1, 3, 2, 5, 8, 3, 9, 4};
    int arr[] = {1, 4443, 222, 5, 98, 23, 79, 14};
    RadixSort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}