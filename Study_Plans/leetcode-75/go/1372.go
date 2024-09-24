package main


type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func longestZigZag(root *TreeNode) int {
    maxZigZag := 0
    var rec func (root *TreeNode, dirIsLeft bool, pathLen int)

    rec = func(root *TreeNode, dirIsLeft bool, pathLen int) {
        if root == nil {
            return 
        }

        maxZigZag = max(maxZigZag, pathLen)

        if dirIsLeft {
            rec(root.Left, false, pathLen + 1)
            rec(root.Right, true, 1)
        } else {
            rec(root.Right, true, pathLen + 1)
            rec(root.Left, false, 1)
        }

        return
    }

    rec(root, true, 0)
    rec(root, false, 0)

    return maxZigZag
}



