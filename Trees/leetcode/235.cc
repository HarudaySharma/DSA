#include<bits/stdc++.h>
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
        TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(!root)
                return nullptr;
            if((root->val <= p->val && root->val >= q->val) ||
                    (root->val >= p->val && root->val <= q->val))
                return root;
            TreeNode *node = nullptr;
            if(root->val > p->val && root->val > q->val)
                node = rec(root->left, p, q);
            if(node)
                return node;
            if(root->val < p->val && root->val < q->val)
                node = rec(root->right, p, q);
            return node;
        }
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            return rec(root, p, q);
        }
};


/* Approach - 2
 *
        pair<bool, bool> globalFound;
        TreeNode* ans = nullptr;

        pair<int, int> rec(TreeNode *root, TreeNode *p, TreeNode *q) {
            pair<bool, bool> found {false, false};
            if(!root || ans)
                return {-1, -1};
            if(root == p){
                found.first = true;
                globalFound.first = true;
                if(globalFound.second == true)
                    return {true, false};
            }
            if(root == q){
                found.second = true;
                globalFound.second = true;
                if(globalFound.first == true)
                    return {false, true};
            }
            auto foundL = rec(root->left, p, q);
            if(ans)
                return found;
            if(foundL.first == true) found.first = true;
            if(foundL.second == true) found.second = true;
            if(found.first == true && found.second == true) {
                ans = root;
            }
            auto foundR = rec(root->right, p, q);
            if(ans)
                return found;
            if(foundR.first == true) found.first = true;
            if(foundR.second == true) found.second = true;
            if(found.first == true && found.second == true) {
                ans = root;
            }
            return found;
        }
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            rec(root, p, q);
            return ans;
        }
};
*/
