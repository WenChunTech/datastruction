package main

type ListNode struct {
	Val  int
	Next *ListNode
}

//  1 -> 2 -> 3 -> 4 -> 5 -> nil

func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	var pre *ListNode
	var cur *ListNode
	var next *ListNode

	cur = head.Next
	pre = nil
	for cur != nil {
		next = cur.Next
		cur.Next = pre
		pre = cur
		cur = next
	}

	head.Next = pre
	return head
}

func print_node(head *ListNode) {
	for head != nil {
		println(head.Val)
		head = head.Next
	}
}

func main() {
	node := ListNode{Next: &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4, Next: &ListNode{Val: 5, Next: nil}}}}}}
	reverseList(&node)
	print_node(&node)
}
