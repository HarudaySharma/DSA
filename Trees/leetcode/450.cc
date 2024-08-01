#include <bits/stdc++.h>
using namespace std;

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
        TreeNode* deleteNode(TreeNode *node) {
            if(!node->right) {
                auto left = node->left;
                delete node;
                return left;
            }
            if(!node->left) {
                auto right = node->right;
                delete node;
                return right;
            }

            TreeNode* curr = node->right;
            while(curr->left)
                curr = curr->left;

            curr->left = node->left;
            auto root = node->right;
            delete node;

            return root;
        }

        bool findAndDelete(TreeNode* root, int &key) {
            if(!root)
                return false;
            if(root->left && root->left->val == key) {
                root->left = deleteNode(root->left);
                return true;
            }
            if(root->right && root->right->val == key) {
                root->right = deleteNode(root->right);
                return true;
            }

            return findAndDelete(root->left, key) 
                || findAndDelete(root->right, key);
        }

        TreeNode* deleteNode(TreeNode* root, int &key) {
            if(!root)
                return nullptr;
            if(root->val == key) {
                return deleteNode(root);
            }

            findAndDelete(root, key);

            return root;
        }
};


