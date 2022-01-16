package main

import "fmt"

func SelectSort(arr []int) {
	var index int
	var temp int
	for i := 0; i < len(arr); i++ {
		index = i // index 记录无序区最小值索引
		for j := i + 1; j < len(arr); j++ {
			if arr[j] < arr[index] {
				index = j
			}
		}
		temp = arr[i]
		arr[i] = arr[index]
		arr[index] = temp
	}
}

func main() {
	arr := []int{2, 5, 3, 5, 6, 8, 1}
	SelectSort(arr)
	fmt.Println(arr)
}
