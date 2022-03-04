package main

import "fmt"

// 二叉树的数据结构
type TreeNode struct {
	Data  int
	Left  *TreeNode
	Right *TreeNode
}

// 二叉树的实现
type Tree struct {
	root *TreeNode
}

// 添加数据
func (self *Tree) Add(data int) {
	var queue []*TreeNode
	newNode := &TreeNode{Data: data}
	if self.root == nil {
		self.root = newNode
	} else {
		queue = append(queue, self.root)
		for len(queue) != 0 {
			cur := queue[0]
			queue = append(queue[:0], queue[0+1:]...)
			// 往右树添加
			if data > cur.Data {
				if cur.Right == nil {
					cur.Right = newNode
				} else {
					queue = append(queue, cur.Right)
				}
				// 往左数添加
			} else {
				if cur.Left == nil {
					cur.Left = newNode
				} else {
					queue = append(queue, cur.Left)
				}
			}
		}
	}
}

// 前序遍历 根 ---> 左 --->右
func (self *Tree) preorderTraverse(node *TreeNode) {
	if node == nil {
		return
	} else {
		fmt.Print(node.Data, " ")
		self.preorderTraverse(node.Left)
		self.preorderTraverse(node.Right)
	}

}

// 中序遍历 左 ---> 根 --->右
func (self *Tree) inorderTraverse(node *TreeNode) {
	if node == nil {
		return
	} else {
		self.inorderTraverse(node.Left)
		fmt.Print(node.Data, " ")
		self.inorderTraverse(node.Right)

	}
}

// 后序遍历 左 ----> 右 ---> 根
func (self *Tree) postTraverse(node *TreeNode) {
	if node == nil {
		return
	} else {
		self.postTraverse(node.Left)
		self.postTraverse(node.Right)
		fmt.Print(node.Data, " ")
	}
}

func main() {
	tree := &Tree{}
	tree.Add(50)
	tree.Add(45)
	tree.Add(40)
	tree.Add(48)
	tree.Add(51)
	tree.Add(61)
	tree.Add(71)

	fmt.Println("前序遍历")
	tree.preorderTraverse(tree.root)
	fmt.Println("")
	fmt.Println("中序遍历")
	tree.inorderTraverse(tree.root)
	fmt.Println("")
	fmt.Println("后续遍历")
	tree.postTraverse(tree.root)
}
