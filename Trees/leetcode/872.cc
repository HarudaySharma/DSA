#include <bits/stdc++.h>
#include <queue>
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
        void getLeaves(TreeNode *root, queue<int> &q) {
            if(!root)
                return;
            if (!root->left && !root->right) {
                return q.push(root->val);
            }
            getLeaves(root->left, q);
            getLeaves(root->right, q);
        }

        bool getLeaves(queue<int> &q, TreeNode *root) {
            if(!root)
                return true;
            if (!root->left && !root->right) {
                if(q.front() == root->val) {
                    q.pop();
                    return true;
                }
                return false;
            }
            return getLeaves(q, root->left) 
                && getLeaves(q, root->right);
        }

        bool leafSimilar(TreeNode *root1, TreeNode *root2) {
            queue<int> seq;
            getLeaves(root1, seq);
            return getLeaves(seq, root2) && seq.empty();
        }
};

