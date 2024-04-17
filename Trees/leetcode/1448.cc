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
    int rec(TreeNode* root, int maxi) {
        if(!root)
            return 0;
        int count = 0;
        if(root->val >= maxi)
            count++;
        count += rec(root->left, max(maxi, root->val));
        count += rec(root->right, max(maxi, root->val));
        return count;
    }
    int goodNodes(TreeNode* root) {
        return rec(root, INT_MIN);
    }
};

