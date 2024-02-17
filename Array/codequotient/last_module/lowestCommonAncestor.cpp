#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BST {
  TreeNode* root;
public:

    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    TreeNode* insertRec(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }

        if (value < root->val) {
            root->left = insertRec(root->left, value);
        } else if (value > root->val) {
            root->right = insertRec(root->right, value);
        }

        return root;
    }

    TreeNode* lowestCommonAncestor(int k1, int k2);
   
};

TreeNode* findNode(TreeNode* root, int target) {
    if(!root) {
        return nullptr;
    }
    if(root->val == target) 
        return root;
    return target > root->val ? findNode(root->right, target)
        : findNode(root->left, target);
}
TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
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

    TreeNode* left = helper(root->left, p, q);
    TreeNode* right = helper(root->right, p, q);

    if(left and right) {
        //lowest common ancestor as we are going top to down
        return root;
    }

    //if (other node is not found in the rest of the Tree):
    //  means its a descendent of this node => this is answer
    return !left ? right : left;
}


TreeNode* BST::lowestCommonAncestor(int k1, int k2) {
    return helper(root, findNode(root, k1), findNode(root, k2));
}

