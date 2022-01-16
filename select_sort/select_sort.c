#include <stdio.h>

void SelectSort(int *arr, int len)
{
    int temp, index;
    for (int i = 0; i < len; i++)
    {
        index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

int main()
{
    int arr[] = {1, 3, 2, 5, 8, 3, 9, 4};
    SelectSort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}