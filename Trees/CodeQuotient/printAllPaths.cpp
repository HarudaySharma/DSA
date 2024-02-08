#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;

        // Constructor to initialize a node with given data
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    private:
        Node* root;
    public:
        BinaryTree(){
            root=nullptr;
        }
        Node * getRoot(){
            return root;
        }
        Node* buildTree(int [], int );
};
Node* BinaryTree::buildTree(int arr[], int n) {
    if (n <= 0 || arr[0] == -1)
        return nullptr;


    Node* root = new Node(arr[0]);
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
    return root;
}


void recurseTree(Node* root, int &count, vector<int>& nodesData) {
    static int leaf = 0;
    if(!root){
        leaf++;
        return;
    }
    if(leaf) {
        leaf = 0;
    }
    nodesData.push_back(root->data);
    recurseTree(root->left, count, nodesData);
    recurseTree(root->right, count, nodesData);
    if(leaf == 2) {
        for(auto el : nodesData) {
            cout << el << " ";
        }
        cout << nodesData.size() - 1 << endl;
        leaf = 0;
        count++;
    } else {
        leaf = 0;
    }
    nodesData.pop_back();
}

void printAllPaths(Node* root) {
    int count = 0;
    vector<int>nodesData;
    recurseTree(root, count, nodesData);
    if(count)
        cout << count;
}

int main() {
    BinaryTree binaryTree;
    int n, i;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];

    //Node* root = nullptr;
 Node* Root=binaryTree.getRoot();
    if (n != 0)
        Root=binaryTree.buildTree(a, n);

    printAllPaths(Root);
    return 0;
}
