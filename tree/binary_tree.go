package main

import "fmt"

/*
				1
		2				3
	4		5		nil 	nil
*/
type TreeNode struct {
	Data  int
	Left  *TreeNode
	Right *TreeNode
}

func PreorderTraverse(node *TreeNode) {
	if node == nil {
		return
	} else {
		fmt.Print(node.Data, " ")
		PreorderTraverse(node.Left)
		PreorderTraverse(node.Right)
	}
}

func InorderTraverse(node *TreeNode) {
	if node == nil {
		return
	} else {
		InorderTraverse(node.Left)
		fmt.Print(node.Data, " ")
		InorderTraverse(node.Right)
	}
}

func PostorderTraverse(node *TreeNode) {
	if node == nil {
		return
	} else {
		PostorderTraverse(node.Left)
		PostorderTraverse(node.Right)
		fmt.Print(node.Data, " ")
	}
}

func main() {
	node3 := TreeNode{3, nil, nil}
	node4 := TreeNode{4, nil, nil}
	node5 := TreeNode{5, nil, nil}
	node2 := TreeNode{2, &node4, &node5}
	node1 := TreeNode{1, &node2, &node3}
	fmt.Print("PreorderTraverse:")
	PreorderTraverse(&node1)
	fmt.Println()
	fmt.Print("InorderTraverse:")
	InorderTraverse(&node1)
	fmt.Println()
	fmt.Print("PostorderTraverse:")
	PostorderTraverse(&node1)
	fmt.Println()
}
