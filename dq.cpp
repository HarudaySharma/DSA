#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    void printLevelWise(BinaryTreeNode<int> *root) {
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto curr = q.front();
                q.pop();
                cout << curr->data << ":";
                cout << "L:";
                if(curr->left) {
                    q.push(curr->left);
                    cout << curr->left->data;
                }
                else {
                    cout << -1;
                }
                cout << ",R:";
                if(curr->right) {
                    q.push(curr->right);
                    cout << curr->right->data;
                }
                else {
                    cout << -1;
                }
                cout << endl;
            }
    }
};

