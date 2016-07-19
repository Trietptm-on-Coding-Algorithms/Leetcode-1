func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	carry, sum := 0, 0
	head := &ListNode{0, nil}
	cur = head
	
	for ; l1 != nil && l2 != nil; l1, l2 = l1.Next, l2.Next {
		sum = l1.Val + l2.Val + carry
		node := &ListNode{sum % 10, nil}
		cur.Next = node
		cur = cur.Next
		carry = sum / 10
	}

	for ; l1 != nil; l1 = l1.Next {
		sum = l1.Val + carry
		node := &ListNode{sum % 10, nil}
		cur.Next = node
		cur = cur.Next
		carry = sum / 10
	}

	for ; l2 != nil; l2 = l2.Next {
		sum = l2.Val + carry
		node := &ListNode{sum % 10, nil}
		cur.Next = node
		cur = cur.Next
		carry = sum / 10
	}

	if carry != 0 {
		node := &ListNode{carry, nil}
		cur.Next = node
	}

	return head.Next
}
