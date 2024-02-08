#include <bits/stdc++.h>
#include <pthread.h>
#include <queue>
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
    bool isLeaf(TreeNode* node) {
        return !node->right && !node->left;
    }
    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        if(isLeaf(root))
            return 1;
        return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
    }
};
