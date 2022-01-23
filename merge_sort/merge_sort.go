package main

import "fmt"

func Merge(arr, temp []int, low, middle, high int) {
	var i int
	num := high - low + 1
	j := middle + 1
	for i = low; low <= middle && j <= high; i++ {
		if arr[low] < arr[j] {
			temp[i] = arr[low]
			low++
		} else {
			temp[i] = arr[j]
			j++
		}
	}
	for low <= middle {
		temp[i] = arr[low]
		i++
		low++
	}
	for j <= high {
		temp[i] = arr[j]
		i++
		j++
	}
	for k := 0; k < num; k++ {
		arr[high] = temp[high]
		high--
	}
}

func MergeSort(arr, temp []int, low, high int) {
	var middle int
	if low < high {
		middle = (low + high) / 2
		MergeSort(arr, temp, low, middle)
		MergeSort(arr, temp, middle+1, high)
		Merge(arr, temp, low, middle, high)
	}
}

func main() {
	arr := []int{2, 5, 3, 5, 6, 8, 1}
	temp := make([]int, 7)
	MergeSort(arr, temp, 0, 6)
	fmt.Println(arr)
}
