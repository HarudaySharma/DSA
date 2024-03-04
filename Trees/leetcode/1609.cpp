#include <bits/stdc++.h>
#include <climits>
#include <queue>
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
    bool solveLvl(queue<TreeNode*> &q, int &prev, bool evenLvl) {
        if(evenLvl) {
            int size =  q.size();
            while(size--) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->val % 2 == 0 || curr->val <= prev)
                    return false;
                prev = curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        else {
            int size =  q.size();
            while(size--) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->val % 2 != 0 || curr->val >= prev)
                    return false;
                prev = curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return true;
    }

    bool BFS(TreeNode* root, int &lvl) {
        if(!root)
            return true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            if(lvl % 2 == 0) {
                int prevMax = -1;
                if(!solveLvl(q, prevMax, true))
                    return false;
            }
            else {
                int prevMin = INT_MAX;
                if(!solveLvl(q, prevMin, false))
                    return false;
            }
            lvl++;
        }
        return true;
    }

    bool isEvenOddTree(TreeNode* root) {
        if(!root)
            return true;
        int lvl = 0;
        return BFS(root, lvl);
    }
};

