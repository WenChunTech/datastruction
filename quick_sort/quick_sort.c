#include <stdio.h>

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

int main()
{
    int arr[] = {1, 3, 2, 5, 8, 3, 9, 4};
    QuickSort(arr, 0, 7);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}