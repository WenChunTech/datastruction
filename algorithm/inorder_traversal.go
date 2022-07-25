package main

import (
	"fmt"
	"syscall"
)

func main() {
	fmt.Println("Hello, 世界")
	syscall.Socket(syscall.AF_INET, syscall.SOCK_STREAM, 0)
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func InorderTraversal(root *TreeNode) []int {
	stack := make([]*TreeNode, 128)
	for root != nil && len(stack) != 0 {
		for root != nil {
			stack = append(stack, root)
			root = root.Left
		}
		if len(stack) != 0 {
			top := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			root = top.Right
		}
	}

	result := make([]int, len(stack))
	for item := range stack {
		result = append(result, item)
	}
	return result

}
