#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
    public:
        int val;
        vector<Node *> neighbors;
        Node() {
            val = 0;
            neighbors = vector<Node *>();
        }
        Node(int _val) {
            val = _val;
            neighbors = vector<Node *>();
        }
        Node(int _val, vector<Node *> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
};

class Solution {
    unordered_map<int, Node *> createdNodes;

    public:
    Node *createNewNode(int val) {
        auto node = new Node(val);
        createdNodes.insert({val, node});
        return node;
    }

    Node *cloneGraph(Node *node) {
        if(!node)
            return nullptr;
        Node *newN = createdNodes.count(node->val) ? createdNodes[node->val]
            : createNewNode(node->val);
        for (auto neighbor : node->neighbors) {
            if (createdNodes.count(neighbor->val)) {
                newN->neighbors.push_back(createdNodes[neighbor->val]);
            } else {
                newN->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return newN;
    }
};
