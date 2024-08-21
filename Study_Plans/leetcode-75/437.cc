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
            set<vector<TreeNode*>> taken;
            auto rec = [&](TreeNode *root, int target, vector<TreeNode*> path, auto &&rec) -> int {
                if(!root)
                    return 0;

                int sum = 0;
                // the next node will be start of the path
                sum += rec(root->left, targetSum, {}, rec);
                sum += rec(root->right, targetSum, {}, rec);

                path.push_back(root);
                target -= root->val;
                if(target < 0)
                    return sum;
                if(target == 0) {
                    if(!taken.count(path)) {
                        taken.insert(path);
                        sum += 1;
                    }
                }
                else {
                    // consider curr node in the path
                    sum += rec(root->left, target, path, rec);
                    sum += rec(root->right, target, path, rec);
                }

                return sum;
            };

            return rec(root, targetSum, {}, rec);
        }
};
