#include <stdio.h>

void ShellSort(int* arr, int len)
{
    int temp, increment, j;
    for (increment = len / 2; increment > 0; increment /= 2)
    {
        for (int i = increment; i < len; i++)
        {
            temp = arr[i];
            for (j = i - increment; j >= 0 && temp < arr[j]; j -= increment)
            {
                arr[j + increment] = arr[j];
            }
            arr[j + increment] = temp;
        }
    }
}

int main()
{
    int arr[] = { 1, 3, 2, 5, 8, 3, 9, 4 };
    ShellSort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}