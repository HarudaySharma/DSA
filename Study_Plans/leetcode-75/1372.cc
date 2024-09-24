#include <bits/stdc++.h>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
    public:
        int longestZigZag(TreeNode *root) {
            int maxZigZag = 0;

            auto rec = [&](TreeNode *root, bool dirIsLeft, int pathLen, auto &&rec) {
                if (!root)
                    return;

                maxZigZag = max(maxZigZag, pathLen);

                if (dirIsLeft) {
                    rec(root->left, false, pathLen + 1, rec);
                    rec(root->right, true, 1, rec);
                } else {
                    rec(root->right, true, pathLen + 1, rec);
                    rec(root->left, false, 1, rec);
                }

                return;
            };

            rec(root, false, 0, rec);
            rec(root, true, 0, rec);

            return maxZigZag;

        }
};
