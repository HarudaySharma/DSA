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
        TreeNode* findRightMostNode(TreeNode *root) {
            if(!root){
                return nullptr;
            }
            if(!root->right) {
                return root;
            }
            return findRightMostNode(root->right);
        }

        void flatten(TreeNode* root) {
            if(!root) {
                return;
            }
            TreeNode *right = root->right;
            TreeNode *left = root->left;
            if(!left)
                flatten(root->right);
            else {
                root->right = left;
                TreeNode *rightMost = findRightMostNode(left);
                if(!rightMost) {
                    left->right = right;
                }
                else {
                    rightMost->right = right;
                }
                root->left = nullptr;
                flatten(root->right);
            }
        }
};

