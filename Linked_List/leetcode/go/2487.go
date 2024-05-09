package main

import (
	"math"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

var mx = math.MinInt64

func rec(curr *ListNode) {
	if curr == nil {
		return
	}
	rec(curr.Next)
	if curr.Next != nil && curr.Next.Val < mx {
        curr.Next = curr.Next.Next
	}
    mx = int(math.Max(float64(mx), float64(curr.Val)))
	return
}

func removeNodes(head *ListNode) *ListNode {
    mx = math.MinInt64
    rec(head)
    if head.Val < mx {
        return head.Next
    }
    return head
}
