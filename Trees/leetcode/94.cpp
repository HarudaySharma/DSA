#include "bits/stdc++.h"
#include <stack>
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        stack<TreeNode*>stk;
        TreeNode* curr = root;
        while(curr || !stk.empty()) {
            while(curr) {
                stk.push(curr);
                curr = curr->left;

            }
            inorder.push_back(stk.top()->val);
            if(stk.top()->right) {
                curr = stk.top()->right;
            }
            stk.pop();
        }
        return inorder;
    }
};
