#include "bits/stdc++.h"
#include <queue>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) {
            return nullptr;
        }
        unordered_map<int, Node*>hash;
        queue<Node*>q;
        q.push(node);
        Node* firstNode = nullptr;

        while (!q.empty()) {
            vector<Node*> _neighbors;
            for(auto neighbor : q.front()->neighbors) {
                auto it = hash.find(neighbor->val);
                if(it == hash.end()) {
                    //create new node
                    Node* newNode = new Node(neighbor->val);
                    hash.insert({newNode->val, newNode});
                    _neighbors.push_back(newNode);
                    // not visited node
                    q.push(neighbor);
                }
                else {
                    _neighbors.push_back(it->second);
                }
            }
            auto it = hash.find(q.front()->val);
            if(it == hash.end()) {
                Node* newNode = new Node(q.front()->val, _neighbors);
                hash.insert({newNode->val, newNode});
                if(!firstNode) {
                    firstNode = newNode;
                }
            }
            else {
                it->second->neighbors = _neighbors;
                if(!firstNode) {
                    firstNode = it->second;
                }
            }
            q.pop();
        }
        return firstNode;
    }
};
