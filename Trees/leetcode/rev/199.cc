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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                if(size == 0) 
                    ans.push_back(curr->val);
            }
        }
        return ans;
    }
};

