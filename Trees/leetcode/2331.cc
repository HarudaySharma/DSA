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
        // leaf: 
        //       0 -> false
        //       1 -> true
        // internal: 
        //       2 -> OR 
        //       3 -> AND
        bool evaluateTree(TreeNode* root) {
            if(!root->left && !root->right) {
                return root->val;
            }

            bool leftEval = true;
            if(root->left) {
                leftEval = evaluateTree(root->left);
            }
            bool rightEval = true;
            if(root->left) {
                rightEval = evaluateTree(root->right);
            }

            return root->val == 2 ? leftEval || rightEval :
                leftEval && rightEval;
        }
};

