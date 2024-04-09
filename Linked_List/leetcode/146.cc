#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *prev;
        Node *next;
        Node(int data, Node *next = nullptr, Node *prev = nullptr)
            : data(data), next(next), prev(prev) {}
};

class LRUCache {
    private:
        map<int, Node*> hash;
        map<Node*, int> inverseHash;
        Node *head;
        Node *tail;
        int capacity;
        int size;
        Node *moveToHead(Node *);

    public:
        LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr), size(0) {}
        ~LRUCache() {
            while (head) {
                tail = head->next;
                delete head;
                head = tail;
            }
        }
        void printList() ;
        void deleteLastNode();
        int get(int key);
        void put(int key, int value);
};

void LRUCache::put(int key, int value) {
    if(hash.count(key)) {
        Node* node = moveToHead(hash[key]);
        node->data = value;
        return;
    }

    if(size == capacity) {
        deleteLastNode();
        size--;
    }

    //check for the empty list
    Node* newN = new Node(value);
    if(!head) {
        head = newN;
        tail = newN;
    }
    else {
        head->prev = newN;
        newN->next = head;
        head = newN;
    }
    hash[key] = head;
    inverseHash[head] = key;
    size++;
    return;
}

int LRUCache::get(int key) {
    if(!hash.count(key)) {
        return -1;
    }
    int data = moveToHead(hash[key])->data;
    return data;
}

void LRUCache::deleteLastNode() {
    Node* tail = this->tail;
    if(tail == head) {
        this->tail = head = nullptr;
    }
    else {
        tail->prev->next = nullptr;
        this->tail = tail->prev;
    }
    // remove from hashmaps
    hash.erase(inverseHash[tail]);
    inverseHash.erase(tail);
    delete tail;
}

Node *LRUCache::moveToHead(Node *node) {
    if(node == this->head)
        return node;
    if(node == tail)
        tail = tail->prev;
    node->prev->next = node->next;
    if(node->next)
        node->next->prev = node->prev;
    node->next = head;
    head->prev = node;
    head = node;
    return head;
}
void LRUCache::printList() {
    Node *curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

