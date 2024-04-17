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
        int maxPathSum(TreeNode* root) {
            int maxPath = INT_MIN;
            auto helper = [&](TreeNode* root, auto &&helper) -> int {
                if(!root){
                    return 0;
                }
                int leftMaxSum = helper(root->left, helper);
                int rightMaxSum = helper(root->right, helper);
                // cause negatives can be there and we need maxPath
                leftMaxSum = max(leftMaxSum, 0);
                rightMaxSum = max(rightMaxSum, 0);
                maxPath = max(maxPath, leftMaxSum + rightMaxSum + root->val);
                return max(leftMaxSum, rightMaxSum) + root->val;
            };
            helper(root, helper);
            return maxPath;
        }
};

