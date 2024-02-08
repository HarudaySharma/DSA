#include <bits/stdc++.h>
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
class Tree {
  Node *root;

public:
  Tree() { root = NULL; }
  Node *getRoot() { return root; }
  void buildTree(int arr[], int n);
};

void Tree::buildTree(int arr[], int n) {
  if (n <= 0 || arr[0] == -1)
    root = NULL;

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

void findKthSmallest(Node *root, int &k, Node **target) {
  if (!root || *target) {
    return;
  }
  if (!root->left && !root->right) {
    k--;
    if (!k) {
      cout << "found: " << root->data;
      *target = root;
    }
    return;
  }
  if (!*target) {
    findKthSmallest(root->left, k, target);
    if (!*target) {
      k--;
      if (!k) {
        cout << "found: " << root->data;
        *target = root;
        return;
      }
      findKthSmallest(root->right, k, target);
    }
  }
}

void inOrderTraversal(Node* root, int &k, int &target) {
    if(!root) 
        return;
    inOrderTraversal(root->left, k, target);
    k--;
    if(!k) {
        target = root->data;
        return;
    }
    inOrderTraversal(root->right, k, target);
}

int kSmallest(Node *root, int k) {
  //Node *target = nullptr;
  //findKthSmallest(root, k, &target);
  //return target ? target->data : -1;
  int target = 0;
  inOrderTraversal(root, k, target);
  return target;
}
