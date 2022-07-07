package main

import (
	"fmt"
)

func BubbleSort(arr []int) {
	var temp int
	for i := 0; i < len(arr)-1; i++ {
		for j := 0; j < len(arr)-1-i; j++ {
			if arr[j] > arr[j+1] {
				temp = arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = temp
			}
		}
	}
}

func main() {
	arr := []int{2, 3, 6, 1, 5, 3, 9, 4}
	BubbleSort(arr)
	fmt.Println(arr)
}
