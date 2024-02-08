#include <algorithm>
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int res = 0;
    int dfs(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int leftPath = dfs(root->left);
        int rightPath = dfs(root->right);
        
        // check if the child has same val as parent
        // if(yes):
        //  add 1 to the childs path 
        // else:
        //  path not formed [path == 0] => (discard childs path)
        int leftCheck = 0, rightCheck = 0;
        if(root->left && root->val == root->left->val) {
            leftCheck = leftPath + 1;
        }
        if(root->right && root->val == root->right->val) {
            rightCheck = rightPath + 1;
        }
        res = max(res, leftCheck + rightCheck);
        return max(leftCheck, rightCheck);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;
    }
};
