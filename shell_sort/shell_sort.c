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

void print_arr(int* arr, int len, char* sort_name) {
    printf("%11s:", sort_name);
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
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
    int arr1[] = { 10, 6, 2, 7, 88, 4, 66, 66, 10, 44 };
    int len = 10;
    ShellSort(arr1, len);
    print_arr(arr1, len, "insert sort");
    return 0;
}