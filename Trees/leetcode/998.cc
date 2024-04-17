#include <bits/stdc++.h>
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
        vector<int> smallestStr;
        vector<int> str;

        string convertToString(vector<int> &smallestStr) {
            string str;
            for(auto it = smallestStr.rbegin(); it != smallestStr.rend(); it++) {
                str.push_back(*it + 'a');
            }
            return str;
        }
        void checkWithSmallest(vector<int> &str) {
            if(smallestStr.empty()) {
                smallestStr = str;
            }
            int i = str.size() - 1;
            int j = smallestStr.size() - 1;
            while(i >= 0 && j >= 0) {
                if(str[i] > smallestStr[j]){
                    return;
                }
                if(str[i] < smallestStr[j]) {
                    smallestStr = str;
                    return;
                }
                i--, j--;
            }
            if(j == 0)
                smallestStr = str;
            return;
        }

        string smallestFromLeaf(TreeNode* root) {

            auto rec = [&](TreeNode *root, auto &&rec){
                str.push_back(root->val);
                if(!root->left && !root->right) {
                    checkWithSmallest(str);
                    str.pop_back();
                    return;
                }
                if(root->left)
                    rec(root->left, rec);
                if(root->right)
                    rec(root->right, rec);
                str.pop_back();
                return;
            };
            rec(root, rec);
            return convertToString(smallestStr);
        }
};

