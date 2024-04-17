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
        int sumOfLeftLeaves(TreeNode* root) {
            int leftSum = 0;
            auto rec = [&](TreeNode* root, auto &&rec) {
                if(!root)
                    return;
                if(root->left && !root->left->left && !root->left->right)
                    leftSum += root->left->val;
                rec(root->left, rec);
                rec(root->right, rec);
                return;

            };
            rec(root, rec);
            return leftSum;
        }
};

