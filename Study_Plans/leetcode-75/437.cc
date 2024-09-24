#include <bits/stdc++.h>
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
        int pathSum(TreeNode* root, int targetSum) {
            if(!root)
                return 0;

            auto rec = [&](TreeNode *root, long target, auto &&rec) -> int {
                if(!root) {
                    return 0;
                }

                long sum = target == root->val ? 1 : 0;

                // consider curr node in the path
                sum += rec(root->left, target - root->val, rec);
                sum += rec(root->right, target - root->val, rec);

                return sum;
            };

            return rec(root, targetSum, rec)
                + pathSum(root->left, targetSum)
                + pathSum(root->right, targetSum);
        }
};
