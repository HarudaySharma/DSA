#include<bits/stdc++.h>
#include <algorithm>
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
    bool ans = true;
    int isBalancedHelper(TreeNode* root) {
        if(!ans || !root)
            return 0;
        int leftHeight = isBalancedHelper(root->left);
        int rightHeight = isBalancedHelper(root->right);
        if(abs(leftHeight - rightHeight) > 1) {
            ans = false;
        }
        return max(leftHeight, rightHeight) + 1;
            
    }
    bool isBalanced(TreeNode* root) {
        isBalancedHelper(root);
        return ans;
    }
};

