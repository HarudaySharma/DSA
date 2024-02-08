#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <map>
#include <string>
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

class Codec {
public:

    void fillString(TreeNode *root, string &str) {
        if(!root) {
            str += "n,";
            return;
        }
        
        str += to_string(root->val);
        str.push_back(',');
        fillString(root->left, str);
        fillString(root->right, str);
        return;
    }
     
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        fillString(root, str);
        // to pop things out in O(1)
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return buildTree(data, i);
    }
    TreeNode* buildTree(string data, int &i) {
        if(i >= data.size())
            return nullptr;

        string val;
        while(i < data.size() && data[i] != ',') {
            val += data[i];
            i++;
        }
        i++;
        if(val == "n") {
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(val));
        root->left = buildTree(data, i);
        root->right = buildTree(data, i);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
