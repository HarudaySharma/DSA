#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// Class representing a node in a binary tree
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        // Constructor to initialize a node with data
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Class representing a binary tree
class BinaryTree {
    private:
        Node* root;

    public:
        // Default constructor to initialize an empty tree
        BinaryTree() : root(nullptr) {}

        // Function to perform a preorder traversal of the tree
        void preOrder(Node* root);

        // Getter function to access the root node
        Node* getRoot() const {
            return root;
        }

        // Setter function to set the root node
        void setRoot(Node* newRoot) {
            root = newRoot;
        }
};

// Function to perform a preorder traversal (visit root, then left subtree, then right subtree)
void BinaryTree::preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << ' ';
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to create a hashmap for efficient lookups of elements in the inorder array
unordered_map<int, int>* buildHashmap(int* in, int n) {
    unordered_map<int, int>* hash = new unordered_map<int, int>;
    for (int i = 0; i < n; i++) {
        hash->insert({in[i], i});  // Map value to its index in the inorder array
    }
    return hash;
}

// function to build the binary tree from inorder and postorder arrays using the hashmap
Node* recurseTree(unordered_map<int, int>* hash, int left, int right, int inLen, int* post, int curr) {
    if (left > right) {
        return nullptr;  // Base case: empty subtree
    }
    int index = hash->at(post[curr]);  // Get the index of the current root element in the inorder array

    // Handle cases where the root element might be located outside the current subtree range
    while (index < left || index > right) {
        curr--;
        index = hash->at(post[curr]);
    }

    Node* root = new Node(post[curr]);  // Create a new node for the root
                                        
    // Recursively build the left and right subtrees using the remaining elements in the postorder array
    root->left = recurseTree(hash, left, index - 1, inLen, post, curr - 1);
    root->right = recurseTree(hash, index + 1, right, inLen, post, curr - 1);
    return root;
}

Node* buildTree(int in[], int post[], int n) {
    unordered_map<int, int>* hash = buildHashmap(in, n);  // Create a hashmap for inorder lookups
    return recurseTree(hash, 0, n - 1, n, post, n - 1);  // Call the recursive function to build the tree
}

int main() {
    BinaryTree binaryTree;

    int n;
    cin >> n;  // Read the number of elements in the tree

    int a[100], b[100];

    for (int i = 0; i < n; i++)
        cin >> a[i];  // Read the inorder array

    for (int i = 0; i < n; i++)
        cin >> b[i];  // Read the postorder array

    // Build the tree using the buildTree function and set it as the root of the binaryTree object
    binaryTree.setRoot(buildTree(a, b, n));

    // Perform a preorder traversal on the built tree
    binaryTree.preOrder(binaryTree.getRoot());

    return 0;
}

