package main

import "fmt"

func RadixSort(arr []int) {
	maxItem := arr[0]
	for i := 1; i < len(arr); i++ {
		if arr[i] > maxItem {
			maxItem = arr[i]
		}
	}

	var count [10]int
	var bucket = make([]int, len(arr))
	exp := 1
	for maxItem/exp > 0 {
		for i := 0; i < 10; i++ {
			count[i] = 0
		}

		for i := 0; i < len(arr); i++ {
			j := arr[i] / exp % 10
			count[j]++
		}

		for i := 1; i < 10; i++ {
			count[i] += count[i-1]
		}

		for i := len(arr) - 1; i >= 0; i-- {
			j := arr[i] / exp % 10
			bucket[count[j]-1] = arr[i]
			count[j]--
		}

		for i := 0; i < len(arr); i++ {
			arr[i] = bucket[i]
		}

		exp *= 10
	}
}

func main() {
	arr := []int{2, 3, 6, 1, 5, 3, 9, 4}
	RadixSort(arr)
	fmt.Println(arr)
}
