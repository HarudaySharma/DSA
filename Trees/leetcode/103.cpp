#include <bits/stdc++.h>
#include <stack>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) {
            return res;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool ltr = true;
        while(!q.empty()) {
            int size = q.size();
            vector<int>lvlNodes;
            // or just give the size of lvlNodes vector
            // and then exploit the random access!
            stack<int>s;
            while(size--) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);

                if(ltr)
                    lvlNodes.push_back(curr->val);
                else{
                    s.push(curr->val);
                }
            }
            if(!ltr) {
                while(!s.empty()) {
                    lvlNodes.push_back(s.top());
                    s.pop();
                }
            }
            res.push_back(lvlNodes);
            ltr = !ltr;
        }
        return res;
    }
};
