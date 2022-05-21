package main

import "fmt"

func BucketSort(arr []int) {
	minItem := arr[0]
	maxItem := arr[0]
	arrLen := len(arr)
	for i := 1; i < arrLen; i++ {
		if maxItem < arr[i] {
			maxItem = arr[i]
		} else if minItem > arr[i] {
			minItem = arr[i]
		}
	}

	bucketSize := (maxItem - minItem) / (arrLen - 1)
	bucketTable := make([][]int, bucketSize*10*8)
	bucketIndexTable := make([]int, 8)

	for i := 0; i < arrLen; i++ {
		bucketIndex := (arr[i] - minItem) / bucketSize
		bucketTable[bucketIndex][bucketIndexTable[bucketIndex]] = arr[i]
		bucketIndexTable[bucketIndex]++
	}

	for i := 0; i < len(bucketTable); i++ {
		if bucketIndexTable[i] != 0 {
			QucikSort(bucketTable[i], 0, bucketIndexTable[i]-1)
		}
	}

	index := 0
	for i := 0; i < bucketSize; i++ {
		if bucketIndexTable[i] != 0 {
			for j := 0; j < bucketIndexTable[i]; j++ {
				arr[index] = bucketTable[i][j]
				index++
			}
		}
	}

}

func QucikSort(arr []int, low, high int) {
	if low < high {
		partitionIndex := Partition(arr, low, high)
		QucikSort(arr, low, partitionIndex-1)
		QucikSort(arr, partitionIndex+1, high)
	}
}

func Partition(arr []int, low, high int) int {
	key := arr[low]
	for low < high {
		for low < high && arr[high] >= key {
			high--
		}
		arr[low] = arr[high]
		for low < high && arr[low] <= key {
			low++
		}
		arr[high] = arr[low]
	}
	arr[low] = key
	return low
}

func main() {
	arr := []int{11, 5, 20, 15, 8, 3, 9, 4, 5, 11}
	BucketSort(arr)
	fmt.Println(arr)
}
