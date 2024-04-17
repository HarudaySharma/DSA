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
    int kthSmallest(TreeNode* root, int k) {
        int ele = -1;
        auto helper = [&](TreeNode* root, auto &&helper) -> void{
            if(!root) 
                return;
            helper(root->left, helper);
            k--;
            if(k == 0)
                ele = root->val;
            helper(root->right, helper);
            return;
        };
        helper(root, helper);
        return ele;
    }
};

