package main

import "fmt"

func CountSort(arr []int) {
	minItem := 100
	maxItem := 0
	for i := 0; i < len(arr); i++ {
		if arr[i] > maxItem {
			maxItem = arr[i]
		}
		if arr[i] < minItem {
			minItem = arr[i]
		}
	}

	itemNum := maxItem - minItem + 1
	var tempArr = make([]int, itemNum)
	for i := 0; i < len(arr); i++ {
		tempArr[arr[i]-minItem] += 1
	}

	index := 0
	for i := 0; i < len(tempArr); i++ {
		for tempArr[i] != 0 {
			arr[index] = minItem + i
			index++
			tempArr[i]--
		}
	}
}

func main() {
	arr := []int{2, 5, 3, 5, 6, 8, 1}
	CountSort(arr)
	fmt.Println(arr)
}
