#include<bits/stdc++.h>
#include <climits>
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
    bool isValidBSTHelper(TreeNode *root, long long maxi, long long mini) {
        if(!root)
            return true;
        if(maxi != LONG_MIN && root->val <= maxi)
            return false;
        if(mini != LONG_MAX && root->val >= mini)
            return false;
        return isValidBSTHelper(root->left, maxi, root->val)
            && isValidBSTHelper(root->right, root->val, mini);

    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
    }
};

