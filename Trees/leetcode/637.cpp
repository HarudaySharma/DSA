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
        vector<double> averageOfLevels(TreeNode* root) {
            vector<double> avgs;
            queue<TreeNode*>q;
            int lvlNodes = 1;
            q.push(root);
            while(!q.empty()) {
                double avg = 0;
                for(int i = 1; i <= lvlNodes; i++) {
                    avg += q.front()->val;
                    if(q.front()->left)
                        q.push(q.front()->left);
                    if(q.front()->right)
                        q.push(q.front()->right);
                    q.pop();
                }
                avg /= lvlNodes;
                avgs.push_back(avg);
                lvlNodes = q.size();
            }
            return avgs;
        }
};
