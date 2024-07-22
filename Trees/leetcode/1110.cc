#include <bits/stdc++.h>
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) {
            return {};
        }

        map<int, TreeNode*> nodes;
        map<int, TreeNode*> parent;
        
        unordered_set<TreeNode*> parents;

        parents.insert(root);
        auto fillHashes = [&](TreeNode *root, auto &&fillHashes) -> void {
            if(!root) {
                return;
            }

            nodes.insert({root->val, root});
            if(root->left) {
                parent[root->left->val] = root;
                fillHashes(root->left, fillHashes);
            }
            if(root->right) {
                parent[root->right->val] = root;
                fillHashes(root->right, fillHashes);
            }
        };

        fillHashes(root, fillHashes);

        for(auto nodeVal : to_delete) {

            // find node on parent 
            auto node = nodes[nodeVal];
            // make it's direct children parents
            if(node->left) {
                parents.insert(node->left);
                parent.erase(node->left->val);
            }
            if(node->right) {
                parents.insert(node->right);
                parent.erase(node->right->val);
            }

            // update it's parent;
            auto pr = parent.find(nodeVal);
            if(pr != parent.end()){
                auto p = pr->second;
                if(p->left && nodeVal == p->left->val) {
                    p->left = nullptr;
                }
                if(p->right && nodeVal == p->right->val) {
                    p->right = nullptr;
                }
            }

            // remove nodes' existence from everywhere
            parents.erase(node);
            nodes.erase(nodeVal);
            delete node;
            
        }

        vector<TreeNode*> res;
        for(auto parent : parents) {
            res.push_back(parent);
        }

        return res;
    }
};
