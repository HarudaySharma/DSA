package Trees.leetcode.rev2.java;

import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public long kthLargestLevelSum(TreeNode root, int k) {
        Queue<TreeNode> q = new LinkedList<>();
        PriorityQueue<Long> pq = new PriorityQueue<>();

        q.add(root);
        while(!q.isEmpty()) {
            int size = q.size();
            long sum = 0;
            while(size-- != 0) {
                var curr = q.poll();
                sum += curr.val;

                if(curr.left != null) {
                    q.add(curr.left);
                }
                if(curr.right != null) {
                    q.add(curr.right);
                }
            }

            if(pq.size() < k) {
                pq.add(sum);
            }
            else {
                if(pq.peek() < sum) {
                    pq.poll();
                    pq.add(sum);
                }
                if(pq.peek() == sum) {// for lvls with same sum
                    pq.add(sum);
                }
            }
        }

        while(pq.size() > k)
            pq.poll();

        return pq.size() < k ? -1 : pq.poll();
    }
}


