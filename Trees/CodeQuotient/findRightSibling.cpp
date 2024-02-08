#include <iostream>
#include <queue>
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
        void insertLevelOrder(int arr[], int i, int n);
        void buildTree(int arr[], int n);
        int findRightSibling(int key);

};
void BinaryTree::insertLevelOrder(int arr[], int i, int n) {
    if (i < n) {
        Node* temp = new Node(arr[i]);
        root = temp;

        insertLevelOrder(arr, 2 * i + 1, n);
        insertLevelOrder(arr, 2 * i + 2, n);
    }
}

void BinaryTree::buildTree(int arr[], int n) {
    if (n <= 0 || arr[0] == -1)
        return;

    root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (i < n && !q.empty()) {
        Node* parent = q.front();
        q.pop();

        // If left child exists
        if (arr[i] != -1) {
            parent->left = new Node(arr[i]);
            q.push(parent->left);
        }
        i++;

        // If right child exists
        if (i < n && arr[i] != -1) {
            parent->right = new Node(arr[i]);
            q.push(parent->right);
        }
        i++;
    }
}

void recurseTree(Node* root, int key, int currLvl, Node **rightSibling){
    static int keyLvl = -1;
    if(!root || *rightSibling) {
        return;
    }
    if(currLvl == keyLvl) {
        *rightSibling = root;
        return;
    }
    if(root->data == key) {
        keyLvl = currLvl;
        return;
    }
    recurseTree(root->left, key, currLvl + 1, rightSibling);
    recurseTree(root->right, key, currLvl + 1, rightSibling);
}

int BinaryTree::findRightSibling(int key) {
    Node* rightSibling = nullptr;
    recurseTree(root, key, 0, &rightSibling);
    return rightSibling ? rightSibling->data : -1;
}

