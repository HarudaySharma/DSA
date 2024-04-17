#include<bits/stdc++.h>
#include <queue>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> lvlOrdr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> lvl;
            while(size--) {
                TreeNode *curr = q.front();
                q.pop();
                lvl.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            lvlOrdr.push_back(lvl);
        }
        return lvlOrdr;
    }
};

