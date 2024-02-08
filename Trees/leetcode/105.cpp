#include <bits/stdc++.h>
#include <map>
#include <vector>
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
        map<int, int> inOrderPos;
        TreeNode* fillTree(TreeNode *root,vector<int> &inorder, int &targetVal) {
            if(!root) {
                TreeNode *newN = new TreeNode(targetVal);
                return newN;
            }
            if(inOrderPos[targetVal] < inOrderPos[root->val]) {
                root->left = fillTree(root->left, inorder, targetVal);
            }
            else {
                root->right = fillTree(root->right, inorder, targetVal);
            }
            return root;
        }

        TreeNode* buildTree(vector<int> &preorder,vector<int> &inorder) {
            TreeNode *root = nullptr;
            for(int i = 0; i < inorder.size(); i++)
                inOrderPos[inorder[i]] = i;

            for(int i = 0; i < preorder.size(); i++) {
                root = fillTree(root, inorder, preorder[i]);
            }
            return root;
        }
};
