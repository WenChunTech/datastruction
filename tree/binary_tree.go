package main

type BinaryTree struct {
	data   int
	lchild *BinaryTree
	rchild *BinaryTree
}

func (tree BinaryTree) New() BinaryTree {
	return BinaryTree{
		data:   0,
		lchild: nil,
		rchild: nil,
	}
}

func (tree BinaryTree) Add(newNode *BinaryTree) {

}

func (tree BinaryTree) PreOrd() {
}

func main() {

}
