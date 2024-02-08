#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Node {
public:
  int data;
  Node *left, *right;
  Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};
class BST {
  Node *root;

public:
  BST() { root = NULL; }
  void buildTree(int arr[], int n);
  int isBinarySearchTree();
};

void BST::buildTree(int arr[], int n) {
  if (n <= 0 || arr[0] == -1)
    return;

  Node *node = new Node(arr[0]);
  queue<Node *> q;
  q.push(node);

  int i = 1;
  while (i < n && !q.empty()) {
    Node *parent = q.front();
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
  root = node;
}

void traverseTree(Node *root, bool &legit, int currMax, int currMin) {
  if (!root || !legit) {
    return;
  }
  if (root->data <= currMin || root->data >= currMax) {
    legit = false;
    return;
  }
  traverseTree(root->left, legit, root->data, currMin);
  traverseTree(root->right, legit, currMax, root->data);
  return;
}
int BST::isBinarySearchTree() {
  if (!root) {
    return 0;
  }
  bool legit = true;
  traverseTree(root, legit, INT_MAX, INT_MIN);
  return legit ? 1 : 0;
}
