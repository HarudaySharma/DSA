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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return nullptr;
        }
        if(root == p or root == q) 
            //found one => now go back and find other one 
            //as other one will either be below this node or not
            //if (other node is not found in the rest of the Tree):
            //  means its a descendent of this node => this is answer
            //else: 
            //  return the common root to which both left and right got
            //  a node when backtracking happened
            return root;
            
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left and right) {
            //lowest common ancestor as we are going top to down
            return root;
        }
        
        //if (other node is not found in the rest of the Tree):
        //  means its a descendent of this node => this is answer
        return !left ? right : left;
    }
};
