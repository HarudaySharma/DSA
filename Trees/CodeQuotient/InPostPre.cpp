#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;
        Node(int val = 0) : data(val), left(nullptr), right(nullptr) {}
};

class  BinaryTree{
    private:
        Node* root;
    public:
        Node* getRoot(){ return root;}
        BinaryTree() : root(nullptr) {}
        Node* insertLevelOrder(vector<int>&,Node *, int, int) ;
        void buildTree(vector<int>&, int);


};

Node* BinaryTree::insertLevelOrder(vector<int>& arr, Node *root,int i, int n) {
    if (i < n) {
        Node* temp = new Node(arr[i]);
        root = temp;

        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

void BinaryTree::buildTree(vector<int>& arr, int n) {
    root = new Node(arr[0]);
    root = insertLevelOrder(arr, root, 0, n);
}
void inorder(Node *root) {
    if(!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void  preorder(Node *root) {
    if(!root) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void  postorder(Node *root) {
    if(!root) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

