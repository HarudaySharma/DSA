#include<bits/stdc++.h>
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
        void invertTreeNodes(TreeNode* root) {
            if(!root)
                return;

            invertTreeNodes(root->left);
            invertTreeNodes(root->right);

            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
            return;

        }
        TreeNode* invertTree(TreeNode* root) {
            invertTreeNodes(root);
            return root;
        }
};
