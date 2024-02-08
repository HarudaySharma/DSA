#include <bits/stdc++.h>
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
    int height(TreeNode* root) {
        if(!root) return 0;
        return max(1 + height(root->right), 1 + height(root->left));
    }

    TreeNode* rotate(TreeNode* root) {
       int heightDiff = height(root->left) - height(root->right);
    
       if(heightDiff > 1) {
           //left heavy
           if(height(root->left->left) - height(root->right->right) > 1) 
               return LLRotate(root);
           else
               return LRRotate(root);
       }
       if(heightDiff < -1) {
           if(height(root->right->left) - height(root->right->right) >= 1) 
               return RLRotate(root);
           else
               return RRRotate(root);
       }
       return root;
    }

    TreeNode* RRRotate(TreeNode* root) {
        TreeNode* rootRight = root->right;
        root->right = rootRight->left;
        rootRight->left = root;
        return rootRight;
    }

    TreeNode* RLRotate(TreeNode* root) {
        // rotate rootLeft to right;
        TreeNode* rootRight = root->right;
        root->right = LLRotate(rootRight);
        return RRRotate(root);
    }

    TreeNode* LRRotate(TreeNode* root) {
        // rotate rootLeft to right;
        TreeNode* rootLeft = root->left;
        root->left = RRRotate(rootLeft);
        return LLRotate(root);
    }

    TreeNode* LLRotate(TreeNode* root) {
        TreeNode* rootLeft = root->left;
        root->left = root->left->right;
        rootLeft->left = root;
        return rootLeft;

    }

    TreeNode* insert(TreeNode* root, int val) {
        if(!root) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        if(root->val < val) {
            root->right = insert(root->right, val);
        }
        else {
            root->left = insert(root->left, val);
        }
        return rotate(root);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = new TreeNode(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            root = insert(root, nums.at(i));
        }
        return root;
    }
};
