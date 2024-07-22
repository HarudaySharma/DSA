#include "bits/stdc++.h"
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
        string getDirections(TreeNode* root, int startValue, int destValue) {

            auto dfs = [&](TreeNode *root, int &target, string &path, auto &&dfs) -> bool {
                if(!root) {
                    return -1;
                }

                if(root->val == target) {
                    return 0;
                }

                path.push_back('L');
                if(dfs(root->left, target, path, dfs)) return 0;
                path.pop_back();


                path.push_back('R');
                if(dfs(root->right, target, path, dfs)) return 0;
                path.pop_back();

                return -1;
            };

            string src;
            dfs(root, startValue, src, dfs);
            string dest;
            dfs(root, destValue, dest, dfs);

            int i = -1;
            while(i < src.length() && i < dest.length()) {
                if(src[i] != dest[i]) {
                    break;
                }
                i++;
            }
            return string(src.length() - i, 'U') + string(dest.begin() + i, dest.end());
        }
};

