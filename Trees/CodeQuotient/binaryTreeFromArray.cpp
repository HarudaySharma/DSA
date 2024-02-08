#include <iostream>
#include <queue>
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
 
  	void inorderTraversal(TreeNode*);
    void printInorder();  
  	void buildTree(int* , int);
};  

void BinaryTree:: inorderTraversal(TreeNode* node) {
	if (node != nullptr) {
		inorderTraversal(node->left);
      	cout << node->data << " ";
		inorderTraversal(node->right);
	}
}

void BinaryTree:: printInorder() {
	if(root!=nullptr)inorderTraversal(root);
	cout << endl;
}

// Complete the buildTree() function which is a member function of the class BinaryTree.

int fetchLeftIndex(int parentIndex) {
    return parentIndex * 2 + 1;
}
int fetchRightIndex(int parentIndex) {
    return parentIndex * 2 + 2;
}

void BinaryTree:: buildTree(int arr[], int n) {
    if(n == 0) 
        return;
    TreeNode* newNode = new TreeNode(arr[0]);
    queue<TreeNode*>q;
    root = newNode;
    q.push(root);
    for(int i = 0; i < n; i++){ 
        TreeNode* parent = nullptr;
        if(!q.empty()) {
            parent = q.front();
            q.pop();
        }
        if(parent) {
            int l = fetchLeftIndex(i);
            if(l < n) {
                parent->left = new TreeNode(arr[l]);
                q.push(parent->left);
            }
            int r = fetchRightIndex(i);
            if(r < n) {
                parent->right = new TreeNode(arr[r]);
                q.push(parent->right);
            }
        }
    }
    
}

