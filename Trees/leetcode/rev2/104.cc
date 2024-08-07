#include <algorithm>
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
        int maxDepth(TreeNode* root) {
            if(!root)
                return 0;

            int leftDepth = maxDepth(root->left) + 1;
            int righDepth = maxDepth(root->right) + 1;
            return std::max(leftDepth, righDepth);
        }
};

