#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
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
        bool dfs(TreeNode *root, long long minVal, long long maxVal) {
            if (!root) {
                return true;
            }
            if(root->val >= minVal || root->val <= maxVal) {
                return false;
            }

            return dfs(root->left, root->val, maxVal) &&
                dfs(root->right, minVal, root->val);
        }
        bool isValidBST(TreeNode *root) { 
            return dfs(root, LLONG_MIN, LLONG_MAX);
        }
};
