#include<bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 */
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>>res;
        vector<vector<int>>result;
        if(!root) {
            return result;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int>lvlNodes;
            while(size--) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                lvlNodes.push_back(curr->val);
            }
            res.push(lvlNodes);
        }
        while(!res.empty()) {
            vector<int>lvlNodes(res.top());
            result.push_back(lvlNodes);
            res.pop();
        }
        return result;
    }
};