#include <stdio.h>
#include <stdlib.h>
#define BUCKETELEMENTNUMBER 10

void QuickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int index = Partition(arr, low, high);
        QuickSort(arr, low, index - 1);
        QuickSort(arr, index + 1, high);
    }
}

int Partition(int *arr, int low, int high)
{
    int key = arr[0];
    while (low < high)
    {
        while (low < high && key <= arr[high])
            --high;
        arr[low] = arr[high];
        while (low < high && key >= arr[low])
            ++low;
        arr[high] = arr[low];
    }
    arr[low] = key;
    return low;
}

void BucketSort(int *arr, int len)
{
    int minItem = 101, maxItem = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] < minItem)
            minItem = arr[i];
        else if (arr[i] > maxItem)
            maxItem = arr[i];
    }
    int bucketLenth = (maxItem - minItem) - (len - 1);
    int **bucketTable = malloc(bucketLenth * BUCKETELEMENTNUMBER * sizeof(int));
    int *bucketIndexTable = (int *)calloc(bucketLenth, sizeof(int *));
    for (int i = 0; i < bucketLenth; i++)
        bucketTable[i] = (int *)calloc(BUCKETELEMENTNUMBER, sizeof(int));

    // add element to bucket
    for (int i = 0; i < len; i++)
    {
        int bucketIndex = (arr[i] - minItem) / bucketLenth;
        bucketTable[bucketIndex][bucketIndexTable[bucketIndex]] = arr[i];
        bucketIndexTable[bucketIndex]++;
    }

    // sort element for each bucket
    for (int i = 0; i < bucketLenth; i++)
        if (bucketIndexTable[i] != 0)
            QuickSort(bucketTable[i], 0, bucketIndexTable[i - 1]);

    // sort array
    int index = 0;
    for (int i = 0; i < bucketLenth; i++)
        if (bucketIndexTable[i] != 0)
            for (int j = 0; j < bucketIndexTable[i]; j++)
                arr[index++] = bucketTable[i][j];
}

int main()
{
    int arr[] = {11, 5, 20, 15, 8, 3, 9, 4, 5, 11};
    BucketSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}