#include <stdio.h>
#define MAXSIZE 8

void Merge(int* arr, int* temp, int low, int middle, int high)
{
    int i, j;
    int num = high - low + 1;
    for (i = low, j = middle + 1; low <= middle && j <= high; i++)
    {
        if (arr[low] < arr[j])
        {
            temp[i] = arr[low++];
        }
        else
        {
            temp[i] = arr[j++];
        }
    }
    while (low <= middle)
    {
        temp[i++] = arr[low++];
    }
    while (j <= high)
    {
        temp[i++] = arr[j++];
    }
    for (int k = 0; k < num; k++, high--)
    {
        arr[high] = temp[high];
    }
}

void MergeSort(int* arr, int* temp, int low, int high)
{
    int middle;
    if (low < high)
    {
        middle = (low + high) / 2;
        MergeSort(arr, temp, low, middle);
        MergeSort(arr, temp, middle + 1, high);
        Merge(arr, temp, low, middle, high);
    }
}

int main()
{
    int arr[] = { 1, 3, 2, 5, 8, 3, 9, 4 };
    int temp[MAXSIZE];
    MergeSort(arr, temp, 0, MAXSIZE - 1);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}