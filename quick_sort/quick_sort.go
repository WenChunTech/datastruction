package main

import "fmt"

func QuickSort(arr []int, low, high int) {
	if low < high {
		index := Partition(arr, low, high)
		QuickSort(arr, low, index-1)
		QuickSort(arr, index+1, high)
	}

}

func Partition(arr []int, low, high int) int {
	key := arr[low]
	for low < high {
		for low < high && arr[high] >= key {
			high--
		}
		arr[low] = arr[high]
		for low < high && key >= arr[low] {
			low++
		}
		arr[high] = arr[low]
	}
	arr[low] = key
	return low
}

func main() {
	arr := []int{2, 3, 6, 1, 5, 3, 9, 4}
	QuickSort(arr, 0, 7)
	fmt.Println(arr)
}
