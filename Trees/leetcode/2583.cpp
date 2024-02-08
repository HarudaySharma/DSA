#include <bits/stdc++.h>
#include <queue>
#include <set>
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
    struct compareDes {
        bool operator()(long long a, long long b) const{
            return a > b;
        }
    };

    long long kthValue(multiset<long long int, compareDes> &l, int &k) {
        auto it = l.begin();
        while(k != 1) {
            it++;
            k--;
        }
        return *it;
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        multiset<long long int, compareDes>sortedSum;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            long long sum = 0;
            while(size--) {
                TreeNode *curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            sortedSum.insert(sum);
        }
        return k > sortedSum.size() ? -1 : kthValue(sortedSum, k);
    }
};
