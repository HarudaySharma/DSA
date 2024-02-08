#include<bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        Node* leftmost = root;
        while(leftmost->left) {
           Node* curr = leftmost;
           while(curr) {
               // parent making its child point to right
               curr->left->next = curr->right;
               if(curr->next != nullptr) {
                   // being done by children
                   curr->right->next = curr->next->left;
                   curr = curr->next;
               }
           }
           leftmost = leftmost->left;
        }
        return root;
    }
};
