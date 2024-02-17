#include<bits/stdc++.h>
using namespace std;

class Node
{
  public: 
	int data;
	Node *left, *right;
	Node(int val){
		data=val;
		left=NULL;
        right=NULL;
	}
};
class Tree{
  Node* root;
  public:
    Tree(){
		root=NULL;
    }
  void buildTree(int arr[], int n);
  Node* getRoot(){
    return root;
  }
};

void Tree::buildTree(int arr[], int n)
{
  if (n <= 0 || arr[0] == -1) {
    root=NULL;
    return;
  }
  Node* node = new Node(arr[0]);
  queue<Node*> q;
  q.push(node);
  int i = 1;
  while (i < n && !q.empty())
  {
    Node* parent = q.front();
    q.pop();
    // If left child exists
    if (arr[i] != -1)
    {
      parent->left = new Node(arr[i]);
      q.push(parent->left);
    }
    i++;
    // If right child exists
    if (i < n && arr[i] != -1)
    {
      parent->right = new Node(arr[i]);
      q.push(parent->right);
    }
    i++;
  }
  root=node;
  return;
}

bool areSameTree(Node* t1, Node* t2) {
    if(!t1 && !t2)
        return true;
    if(!t1 || !t2)
        return false;
    if(t1->data != t2->data) 
        return false;
    
    return areSameTree(t1->left, t2->left) and
        areSameTree(t1->right, t2->right);
}
