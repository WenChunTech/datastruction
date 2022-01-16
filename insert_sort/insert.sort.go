package main

import "fmt"

func InserSort(arr []int) {
	var i, j, temp int
	for i = 1; i < len(arr); i++ {
		if arr[i-1] > arr[i] {
			temp = arr[i]
			for j = i - 1; j >= 0 && arr[j] > temp; j-- {
				arr[j+1] = arr[j]
			}
			arr[j+1] = temp
		}
	}
}

func main() {
	arr := []int{2, 5, 3, 5, 6, 8, 1}
	fmt.Println(len(arr))
	InserSort(arr)
	fmt.Println(arr)
}
