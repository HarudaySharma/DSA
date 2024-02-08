/**
 * Definition for a binary tree node.
 */
#include <bits/stdc++.h>
#include <climits>
using namespace std;

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
    int maxPath = INT_MIN;
    int findMaxPathSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int leftSum = findMaxPathSum(root->left);
        int rightSum = findMaxPathSum(root->right);
        
        leftSum = max(leftSum, 0);
        rightSum = max(rightSum, 0);

        int pathSum = leftSum + rightSum + root->val;
        maxPath = max(maxPath, pathSum);

        return max(leftSum, rightSum) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        findMaxPathSum(root);
        return maxPath;
    }
};
