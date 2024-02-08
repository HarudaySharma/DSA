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
        bool checkSymmetric(TreeNode *Left, TreeNode *Right) {
            if (!Left && !Right)
                return true;
            if ((!Left && Right) || (!Right && Left))
                return false;
            if (Left->val != Right->val) {
                return false;
            }
            return checkSymmetric(Left->left, Right->right) &&
                checkSymmetric(Left->right, Right->left);
        }
        bool isSymmetric(TreeNode *root) {
            return checkSymmetric(root->left, root->right);
        }
};
