#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void print_arr(int* arr, int len, char* sort_name) {
    printf("%11s:", sort_name);
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

void insert_sort(int* arr, int len) {
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] < arr[i - 1]) {
            int temp = arr[i];
            for (j = i - 1; j >= 0 && temp < arr[j]; j--) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}

void shell_sort(int* arr, int len) {
    int j = 0;
    for (int increment = len / 2; increment > 0; increment /= 2) {
        for (int i = increment; i < len; i++) {
            if (arr[i] < arr[i - increment]) {
                int temp = arr[i];
                for (j = i - increment; j >= 0 && temp < arr[j]; j -= increment) {
                    arr[j + increment] = arr[j];
                }
                arr[j + increment] = temp;
            }
        }
    }
}

void select_sort(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        int min_item_index = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[min_item_index] > arr[j]) {
                min_item_index = j;
            }
        }
        swap(arr, min_item_index, i);
    }
}

int partition(int* arr, int low, int high) {
    int key = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= key) --high;
        arr[low] = arr[high];
        while (low < high && arr[low] <= key) ++low;
        arr[high] = arr[low];
    }
    arr[low] = key;
    return low;
}

void quick_sort(int* arr, int low, int high) {
    if (low < high) {
        int partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
}

void merge(int* arr, int* temp, int left, int middle, int right) {
    int i = left;
    int j = middle + 1;
    int num = right - left + 1;
    while (left <= middle && j <= right) {
        temp[i++] = arr[left] < arr[j] ? arr[left++] : arr[j++];
    }
    while (left <= middle) {
        temp[i++] = arr[left++];
    }
    while (j <= right) {
        temp[i++] = arr[j++];
    }
    for (i = 0; i < num; i++) {
        arr[right--] = temp[right];
    }

}

void heap_adjust(int* arr, int i, int len) {
    int temp = arr[i];
    for (int j = i * 2 + 1; j < len; j = j * 2 + 1) {
        if (j < len - 1 && arr[j] < arr[j + 1]) j++;
        if (arr[j] <= temp) break;
        arr[i] = arr[j];
        i = j;
    }
    arr[i] = temp;
}

void heap_sort(int* arr, int len) {
    for (int i = len / 2; i >= 0; i--) {
        heap_adjust(arr, i, len);
    }
    for (int i = len - 1; i > 0; i--) {
        swap(arr, 0, i);
        heap_adjust(arr, 0, i);
    }
}

void merge_sort(int* arr, int* temp, int low, int high) {
    int middle;
    if (low < high) {
        middle = (low + high) / 2;
        merge_sort(arr, temp, low, middle);
        merge_sort(arr, temp, middle + 1, high);
        merge(arr, temp, low, middle, high);
    }

}

void radix_sort(int* arr, int len) {
    int max_item = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max_item) {
            max_item = arr[i];
        }
    }

    int max_item_radix = 1;
    int base = 1;
    while (max_item / base > 0) {
        base *= 10;
        max_item_radix++;
    }

    base = 1;
    int* temp = (int*)malloc(sizeof(int) * len);
    for (int i = 0; i < max_item_radix; i++) {
        int count[10] = { 0 };
        for (int j = 0; j < len; j++) {
            count[arr[j] / base % 10]++;
        }
        for (int j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }
        for (int j = len - 1; j >= 0; j--) {
            temp[count[arr[j] / base % 10] - 1] = arr[j];
            count[arr[j] / base % 10]--;
        }
        for (int j = 0; j < len; j++) {
            arr[j] = temp[j];
        }
        base *= 10;
    }
    free(temp);
}

void count_sort(int* arr, int len) {
    int max_item = arr[0];
    int min_item = arr[0];
    for (int i = 1; i < len; i++) {
        if (max_item < arr[i]) {
            max_item = arr[i];
        }
        else if (min_item > arr[i]) {
            min_item = arr[i];
        }
        else {
            continue;
        }
    }

    int bucket_size = max_item - min_item + 1;
    int* count = (int*)calloc(bucket_size, sizeof(int));
    for (int i = 0; i < len; i++) {
        count[arr[i] - min_item]++;
    }

    int index = 0;
    for (int i = 0; i < bucket_size; i++) {
        while (count[i] > 0) {
            arr[index++] = min_item + i;
            count[i]--;
        }
    }
    free(count);
}

void bucket_sort(int* arr, int len) {
    // to do
}

int main() {
    int arr1[] = { 10, 6, 2, 7, 88, 4, 66, 66, 10, 44 };
    int len = 10;
    insert_sort(arr1, len);
    print_arr(arr1, len, "insert sort");

    int arr2[] = { 10, 6, 2, 7, 88, 4, 66, 66, 10, 44 };
    shell_sort(arr2, len);
    print_arr(arr2, len, "shell sort");

    int arr3[] = { 10, 6, 2, 7, 88, 4, 66, 66, 10, 44 };
    select_sort(arr3, len);
    print_arr(arr3, len, "select sort");

    int arr4[] = { 10, 6, 2, 7, 88, 4, 66, 66, 10, 44 };
    quick_sort(arr4, 0, len - 1);
    print_arr(arr4, len, "qucik sort");

    int arr5[] = { 10, 6, 2, 7, 88, 4, 66, 66, 10, 44 };
    heap_sort(arr5, len);
    print_arr(arr5, len, "heap sort");

    int arr6[] = { 10, 6, 2, 7, 88, 4, 66, 66, 10, 44 };
    merge_sort(arr5, arr6, 0, len - 1);
    print_arr(arr5, len, "merge sort");

    int arr7[] = { 10, 6, 2, 7, 88, 4, 66, 66, 10, 44 };
    radix_sort(arr7, len);
    print_arr(arr7, len, "radix sort");

    int arr8[] = { 10, 6, 2, 7, 88, 4, 66, 66, 10, 44 };
    count_sort(arr8, len);
    print_arr(arr8, len, "count sort");
    return 0;
}