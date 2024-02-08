#include <algorithm>
#include <bits/stdc++.h>
#include <map>
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
    int maxWidth = 0;
    map<int, int>leftmostPositions;

    int widthOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        getMaxWidth(root, 0, 1);
        return maxWidth;
    }
    void getMaxWidth(TreeNode* root, int lvl, int position) {
        if(!root) return;
        if(!leftmostPositions.count(lvl)) {
            leftmostPositions[lvl] = position;
        }
        maxWidth = max(position - leftmostPositions[lvl] + 1, maxWidth);
        getMaxWidth(root->left, lvl + 1, position * 2);
        getMaxWidth(root->right, lvl + 1, position * 2 + 1);
    }
};
