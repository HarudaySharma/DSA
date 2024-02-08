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
    TreeNode* root;
public:
    BinaryTree() : root(nullptr) {}
  TreeNode* getRoot(){
    return root;
  }
  	void buildTree(int* , int );
  
  	int countLeafs(TreeNode*);
  	
  	int countNonLeafs(TreeNode*);
};

void BinaryTree:: buildTree(int* nodes, int n) {
	if (n == 0) return;

	queue<TreeNode*> q;

	root = new TreeNode(nodes[0]);
	q.push(root);

	for (int i = 1; i < n; i += 2) {
		TreeNode* current = q.front();
		q.pop();

		if (nodes[i] != -1) {
        	current->left = new TreeNode(nodes[i]);
			q.push(current->left);
		}

		if (i + 1 < n && nodes[i + 1] != -1) {
			current->right = new TreeNode(nodes[i + 1]);
          	q.push(current->right);
        }
    }
}
void recurseTree(TreeNode* root, int &count) {
    if(!root) {
        return;
    }
    if(!root->left && !root->right)
        count++;
    recurseTree(root->left, count);
    recurseTree(root->right, count);
    return;
}

int BinaryTree::countLeafs(TreeNode* node) {
    int count = 0;
    recurseTree(node, count);
    return count;
}
void recurseTree2(TreeNode* root, int &count) {
    if(!root) {
        return;
    }
    if(root->left || root->right)
        count++;
    recurseTree2(root->left, count);
    recurseTree2(root->right, count);
    return;
}

int BinaryTree::countNonLeafs(TreeNode* node) {
    int count = 0;
    recurseTree2(root, count);
    return count;
}


