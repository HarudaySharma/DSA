#include <bits/stdc++.h>
#include <sstream>

using namespace std;

struct TreeNode {
    long val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(long x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(long x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}
};

class Solution {
public:
    string tree2str(TreeNode* root) {
        return preOrderTraversal(root);
    }

    string preOrderTraversal(TreeNode *root) {
        if(!root) {
            return "";
        }

        stringstream ss;
        ss << root->val;

        string leftStr = preOrderTraversal(root->left);
        string rightStr = preOrderTraversal(root->right);

        // accomplying with the guidelines
        if(leftStr.empty() && rightStr.empty()) {
            return ss.str();
        }

        ss << "(" << leftStr << ")";
        if(!rightStr.empty()) {
            ss << "(" << rightStr << ")";
        }

        return ss.str();
    }
};

