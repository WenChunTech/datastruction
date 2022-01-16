package main

import "fmt"

func ShellSort(arr []int) {
	var increament int
	var temp int
	var j int
	for increament = len(arr) / 2; increament > 0; increament /= 2 {
		for i := increament; i < len(arr); i++ {
			temp = arr[i]
			for j = i - increament; j >= 0 && arr[j] > temp; j -= increament {
				arr[j+increament] = arr[j]
			}
			arr[j+increament] = temp
		}
	}
}

func main() {
	arr := []int{2, 3, 6, 1, 5, 3, 9, 4}
	ShellSort(arr)
	fmt.Println(arr)
}
