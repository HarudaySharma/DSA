#include <bits/stdc++.h>
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
    TreeNode* createNewRoot(TreeNode *root, int val) {
        TreeNode *newN = new TreeNode(val, root, nullptr);
        return newN;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            root = createNewRoot(root, val);
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(depth > 2 && !q.empty()) {
            depth--;
            int size = q.size();
            while(size--) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            // creating a new TreeNode
            TreeNode* newLeftNode = new TreeNode(val);
            newLeftNode->left = curr->left;
            // rightNode
            TreeNode* newRightNode = new TreeNode(val);
            newRightNode->right = curr->right;
            // making both of them child of curr;
            curr->left = newLeftNode;
            curr->right = newRightNode;
        }
        return root;
    }
};

