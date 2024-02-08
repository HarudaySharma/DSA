#include "bits/stdc++.h"
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printOdd(Node* root) {
    if(!root) {
        return;
    }
    int level = 1;
    queue<Node*> *q = new std::queue<Node*>;
    q->push(root);
    while(!q->empty()) {
        int nodeCount = q->size();
        while(nodeCount--) {
            Node* parent = q->front();
            q->pop();
            if(level % 2 != 0) {
                if(level != 1) {
                    cout << " ";
                }
                cout << parent->data;
            }
            if(parent->left) {
                q->push(parent->left);
            }
            if(parent->right) {
                q->push(parent->right);
            }
        }
        level++;
    }
}

int main (int argc, char *argv[]) {
    
    return 0;
}
