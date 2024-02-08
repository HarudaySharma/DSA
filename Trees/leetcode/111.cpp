#include "bits/stdc++.h"
#include <queue>
using namespace std;


// Definition for a binary tree node.
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
        int minDepth(TreeNode* root) {
            if(!root) {
                return 0;
            }
            queue<TreeNode*>q;
            q.push(root);
            int lvlNodes = q.size();
            int lvl = 1;
            while(!q.empty()) {
                for(int i = 1; i <= lvlNodes; i++) {
                    if(!q.front()->left && !q.front()->right)
                        return lvl;
                    if(q.front()->left)
                        q.push(q.front()->left);
                    if(q.front()->right)
                        q.push(q.front()->right);
                    q.pop();
                }
                lvlNodes = q.size();
                lvl++;
            }
            return lvl;
        }
};

