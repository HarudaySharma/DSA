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
        TreeNode* removeLeafNodes(TreeNode* root, int target) {

            auto rec = [&](TreeNode *root, auto &&rec) -> TreeNode* {
                if(!root)
                    return nullptr;
                root->left = rec(root->left, rec);
                root->right = rec(root->right, rec);
                if(root->val == target && !root->left && !root->right) {
                    return nullptr;
                }
                return root;
            };

            return rec(root, rec);
        }
};

