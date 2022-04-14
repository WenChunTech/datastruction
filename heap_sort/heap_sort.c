#include <stdio.h>

void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void HeapAdjust(int* arr, int i, int len)
{
    int temp = arr[i];
    for (int j = 2 * i + 1; j < len; j = 2 * j + 1)
    {
        if (j < len - 1 && arr[j] < arr[j + 1]) ++j;
        if (!(arr[j] > temp)) break;
        arr[i] = arr[j];
        i = j;
    }
    arr[i] = temp;
}

void HeapSort(int* arr, int len)
{
    for (int i = len / 2; i >= 0; i--)
    {
        HeapAdjust(arr, i, len);
    }
    for (int i = len - 1; i >= 0; i--)
    {
        swap(arr, 0, i);
        HeapAdjust(arr, 0, i);
    }
}

int main()
{
    int arr[] = { 2, 5, 3, 5, 6, 8, 1 };
    HeapSort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}