#include<bits/stdc++.h>
#include <queue>
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) {
            return false;
        }
        queue<TreeNode*>q;
        q.push(root);

        bool xFound = false;
        bool yFound = false;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) {
                    if(curr->left->val == x) {
                        xFound = true;
                        if(curr->right) {
                            if(curr->right->val == y)
                                return false;
                        }
                    }
                    else if(curr->left->val == y) {
                        yFound = true;
                        if(curr->right) {
                            if(curr->right->val == x)
                                return false;
                        }
                    }
                    q.push(curr->left);
                }
                if(curr->right) {
                    if(curr->right->val == x) {
                        xFound = true;
                        if(curr->left) {
                            if(curr->left->val == y)
                                return false;
                        }
                    }
                    else if(curr->right->val == y) {
                        yFound = true;
                        if(curr->left) {
                            if(curr->left->val == x)
                                return false;
                        }
                    }
                    q.push(curr->right);
                }
            }
            if(xFound && yFound) 
                return true;

            if(xFound || yFound)
                return false;
        }
        return false;
    }
};
