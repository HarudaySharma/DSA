#include<bits/stdc++.h>
#include <iterator>
#include <queue>
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
  	void buildTree(int arr[], int);
    void printLevelWise();
};

void Tree::buildTree(int arr[], int n)
{
  if (n <= 0 || arr[0] == -1) return;
  
  Node* node = new Node(arr[0]);
  queue <Node*> q;
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
}

void printSpace(int size) {
    if(size){
        cout << " ";
    }
}
void printLevel(queue<Node*> *q, int size) {
    while(size--) {
        Node* parent = q->front();
        cout << parent->data;
        q->pop();
        if(parent->left){
            q->push(parent->left);
        }
        if(parent->right){
            q->push(parent->right);
        }
        printSpace(size);
    }
    cout << endl;
}

void Tree::printLevelWise() {
    if(!root) {
        return;
    }
    queue<Node*> *q = new queue<Node*>;
    q->push(root);
    int qsize = q->size();
    while(!q->empty()) {
            printLevel(q, qsize);
            qsize = q->size();
    }
    delete q;
}
