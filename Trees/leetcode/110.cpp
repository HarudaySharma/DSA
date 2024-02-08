#include "bits/stdc++.h"
#include <unordered_map>
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
    // get height of all the nodes
    // dfs =>(backtracking)
    unordered_map<TreeNode*, int>height;

    int getHeight(TreeNode* root) {
        if(!root) {
            return 0;
        }
        auto it = height.find(root);
        if(it != height.end())
            return it->second;
        height[root] = max(1 + getHeight(root->left), 1 + getHeight(root->right)); 
        return height[root];
    }

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        isBalanced(root->left);
        isBalanced(root->right);
        if(abs(getHeight(root->left) - getHeight(root->right)) > 1) {
            return false;
        }
        return true;
    }
};
