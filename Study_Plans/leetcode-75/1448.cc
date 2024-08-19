#include <algorithm>
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
        int goodNodes(TreeNode *root) {

            auto traverse = [&](TreeNode *root, int maxTillNow, auto &&traverse) -> int {
                if (!root)
                    return 0;

                int goodChildren =
                    traverse(root->left, max(maxTillNow, root->val), traverse) +
                    traverse(root->right, max(maxTillNow, root->val), traverse);

                return root->val >= maxTillNow ? 1 + goodChildren : goodChildren;
            };

            return traverse(root, INT_MIN, traverse);
        }
};
