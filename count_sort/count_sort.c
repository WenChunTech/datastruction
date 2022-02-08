#include <stdio.h>
#include <stdlib.h>

void CountSort(int *arr, int len)
{
    int minItem, maxItem;
    minItem = 100;
    maxItem = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > maxItem)
            maxItem = arr[i];
        if (arr[i] < minItem)
            minItem = arr[i];
    }
    int itemNum = maxItem - minItem + 1;
    int *tempArr = (int *)calloc(itemNum, sizeof(int));
    for (int i = 0; i < len; i++)
    {
        tempArr[arr[i] - minItem]++;
    }

    int index = 0;
    for (int i = 0; i < itemNum; i++)
    {
        while (tempArr[i] != 0)
        {
            arr[index++] = i + minItem;
            tempArr[i]--;
        }
    }
    free(tempArr);
}

int main()
{
    int arr[] = {2, 5, 3, 5, 6, 8, 1};
    CountSort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}