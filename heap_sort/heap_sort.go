package main

import "fmt"

func swap(arr []int, i, j int) {
	temp := arr[i]
	arr[i] = arr[j]
	arr[j] = temp
}

func HeapSort(arr []int, len int) {
	for i := len / 2; i >= 0; i-- {
		HeapAdjust(arr, i, len)
	}
	for i := len - 1; i > 0; i-- {
		swap(arr, 0, i)
		HeapAdjust(arr, 0, i)
	}
}

func HeapAdjust(arr []int, i, len int) {
	temp := arr[i]
	for j := i*2 + 1; j < len; j = j*2 + 1 {
		if j+1 < len && arr[j] < arr[j+1] {
			j++
		}
		if arr[j] > temp {
			arr[i] = arr[j]
			i = j
		} else {
			break
		}
	}
	arr[i] = temp
}

func main() {
	arr := []int{2, 5, 3, 5, 6, 8, 1}
	HeapSort(arr, 7)
	fmt.Println(arr)
}
