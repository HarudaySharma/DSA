#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
        bool isSubPath(ListNode* head, TreeNode* root) {
            if(!root) {
                return false;
            }
            return treeHasList(head, root) || 
                (isSubPath(head, root->left) ||
                isSubPath(head, root->right));
        }

        bool treeHasList(ListNode* head, TreeNode* root) {
            if(!head) {
                return true;
            }
            if(!root) {
                return false;
            }
            if(root->val == head->val) {
                return treeHasList(head->next, root->left)
                    || treeHasList(head->next, root->right);
            }
            return false;
        }
};

