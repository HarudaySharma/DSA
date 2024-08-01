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
    int maxLevelSum(TreeNode* root) {
        if(!root) 
            return 0;

        int maxLvl = 1;
        int maxSum = INT_MIN;
        int lvl = 1;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int sum = 0;
            while (size--) {
                auto curr = q.front();
                q.pop();

                sum += curr->val;

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(sum > maxSum) {
                maxLvl = lvl;
                maxSum = sum;
            }
            lvl++;
        }

        return maxLvl;
    }
};

