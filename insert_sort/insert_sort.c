#include <stdio.h>
#define MAXSIZE 20

// typedef int KeyType;

// typedef struct
// {
//     KeyType key;
// } RedType;

// typedef struct
// {
//     RedType r[MAXSIZE + 1];
//     int length;
// } SqList;

void InsertSort(int *arr, int len)
{
    int temp, i, j;
    for (i = 1; i < len; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            temp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > temp; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}

int main()
{
    int arr[] = {2, 5, 3, 5, 6, 8, 1};
    InsertSort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
