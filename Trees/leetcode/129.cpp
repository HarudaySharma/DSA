#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
    public:
        // 5 * 1 + 9 * 10 + 4 * 100 => 495
        // 40 + 9 => 49 => 490
        int findSum(TreeNode *root, int number) {
            if (!root) {
                return 0;
            }
            if (!root->left && !root->right) {
                number *= 10;
                number += root->val;
                return number;
            }
            number *= 10;
            number += root->val;
            return findSum(root->left, number) + findSum(root->right, number);
        }
        int sumNumbers(TreeNode *root) {
            findSum(root, 0);
            return findSum(root, 0);
        }
};
