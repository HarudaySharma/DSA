#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    private:
        TreeNode* root;

    public:
        BinaryTree() : root(nullptr) {}
        TreeNode* createBinaryTree(int values[], int n);
        void inorderTraversal();

};
TreeNode* BinaryTree:: createBinaryTree(int values[], int n) {
    if (n == 0) {
        return nullptr;
    }

    root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);

    for (int i = 1; i < n; i += 2) {
        TreeNode* current = q.front();
        q.pop();

        if (values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }

        if (i + 1 < n && values[i + 1] != -1) {
            current->right = new TreeNode(values[i + 1]);
            q.push(current->right);
        }
    }

    return root;
}

void BinaryTree:: inorderTraversal() {
    stack<TreeNode*> *s = new stack<TreeNode*>;
    TreeNode* curr = root;
    while(curr || !s->empty()) {
        while(curr) {
            s->push(curr);
            curr = curr->left;
        }
        cout << s->top()->data << " ";
        if(s->top()->right) {
           curr = s->top()->right; 
        }
        s->pop();
    }
}


