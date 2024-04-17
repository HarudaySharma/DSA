#include<bits/stdc++.h>
#include <exception>
#include <queue>
#include <vector>
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
    void insertToTree(TreeNode* root,  TreeNode* newN, map<int, int> &pos) {
        if(pos[newN->val] > pos[root->val]) {
            if(!root->right) {
                root->right = newN;
                return;
            }
            insertToTree(root->right, newN, pos);
        }
        else {
            if(!root->left) {
                root->left = newN;
                return;
            }
            insertToTree(root->left, newN, pos);
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> pos;
        for(int i = 0; i < inorder.size(); i++){
            pos[inorder[i]] = i;
        }
        TreeNode* root = nullptr;
        for(auto data : preorder) {
            TreeNode* newN = new TreeNode(data);
            if(!root) {
                root = newN;
                continue;
            }
            insertToTree(root, newN, pos);
        }
        return root;
    }
};

