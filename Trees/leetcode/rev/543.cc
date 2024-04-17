#include<bits/stdc++.h>
#include <algorithm>
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
        int maxDiameter = 0;
        int diameterOfBinaryTreeHelper(TreeNode *root) {
            if(!root)
                return 0;
            int leftHeight = diameterOfBinaryTreeHelper(root->left);
            int rightHeight = diameterOfBinaryTreeHelper(root->right);
            maxDiameter = max(maxDiameter, leftHeight + rightHeight);
            return max(leftHeight, rightHeight) + 1;
        }
        int diameterOfBinaryTree(TreeNode* root) {
            diameterOfBinaryTreeHelper(root);
            return maxDiameter;
        }
};


