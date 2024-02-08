#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() : root(nullptr) {}
    void preOrder(Node* root);

    // Function to get the root (getter)
    Node* getRoot() const {
        return root;
    }

    // Function to set the root (setter)
    void setRoot(Node* newRoot) {
        root = newRoot;
    }
};

void BinaryTree::preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << ' ';
        preOrder(root->left);
        preOrder(root->right);
    }
}

unordered_map<int, int> * buildHashmap (int *in, int n) { unordered_map<int, int> *hash = new unordered_map<int, int>;
    for(int i = 0; i < n; i++) {
        hash->insert({in[i], i});
    }
    return hash;
}


Node* recurseTree(unordered_map<int, int> *hash , int left, int right, int inLen, int *post, int curr) {
    if(left > right) {
        return nullptr;
    }
    int index = hash->at(post[curr]);
    while(index < left || index > right) {
        curr--;
        index = hash->at(post[curr]);
    }
    Node* root = new Node(post[curr]);
    root->left = recurseTree(hash, left, index - 1, inLen, post, curr - 1);
    root->right = recurseTree(hash, index + 1, right, inLen, post, curr - 1);
    return root;

}

Node* buildTree(int in[], int post[], int n) {
    unordered_map<int, int> *hash =  buildHashmap(in, n);
    return recurseTree(hash, 0, n - 1, n, post, n - 1);
}

int main() {
    BinaryTree binaryTree;

    int n;
    cin >> n;

    int a[100], b[100];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    // Use the setter function to set the root
    binaryTree.setRoot(buildTree(a, b, n));
    binaryTree.preOrder(binaryTree.getRoot());

    return 0;
} 


