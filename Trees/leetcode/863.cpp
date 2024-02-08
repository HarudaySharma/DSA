#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * we can find the nodes below the target easily
 * but we need some kind of connection b/w the child and parent
 * so that we can find those nodes which are not descendent of the target node
 * 
 * after having that relation now we can use this to get to those nodes which
 * were not descendent of the target node too.
 * how? implement BFS till k != currLevel
 *      the nodes left in the queue after the BFS are
 *      target Nodes.
 */
class Solution {
public:
    unordered_map<int, TreeNode*>parent;
    void preOrder(TreeNode* child, TreeNode* par) {
        if(!child) {
            return;
        }
        parent[child->val] = par;
        preOrder(child->left, child);
        preOrder(child->right, child);
        return;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        preOrder(root, nullptr);
        
        unordered_set<int>visited;
        queue<TreeNode*>q;
        q.push(target);
        while(!q.empty() && k) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode *curr = q.front();
                q.pop();
                visited.insert(curr->val);
                if(curr->left && !visited.count(curr->left->val)) {
                    q.push(curr->left);
                }
                if(curr->right && !visited.count(curr->right->val)) {
                    q.push(curr->right);
                }
                if(parent[curr->val] && !visited.count(parent[curr->val]->val)) {
                    q.push(parent[curr->val]);
                }
            }
            k--;
        }
        vector<int> targetNodes;
        while(!q.empty()) {
            targetNodes.push_back(q.front()->val);
            q.pop();
        }
        return targetNodes;
    }
};
