#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// Implement the LRUCache class:
//
//     LRUCache(int capacity) Initialize the LRU cache with positive size
//     capacity.
//
//     int get(int key) Return the value of the key if the key exists,
//     otherwise return -1.
//
//     void put(int key, int value) Update the value of the
//     key if the key exists. Otherwise, add the key-value pair to the cache.
//
//     If the number of keys exceeds the capacity from this operation, evict the
//     least recently used key.
//
// The functions get and put must each run in O(1) average time complexity.

class LRUCache {
private:
    class Node {
    public:
        int value, key;
        Node *next;
        Node *prev;
        Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) { }

    };

    Node* head; // head will point to most recently used key
    Node *tail; // will point to the least recently used key.

    unordered_map<int, Node *> hashTable; // {key, node}
    int capacity;

public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) { }

    int get(int key) {
        if(hashTable.count(key)) {
            Node *node = hashTable[key];
            moveToHead(node);

            return node->value;
        }

        return -1;
    }

    void put(int key, int value) {
        // is key is already present in the cache.
        if(hashTable.count(key)) {
            moveToHead(hashTable[key]);
            hashTable[key]->value = value;
            return;
        }

        // check if their is capacity
        if(hashTable.size() == capacity) {
            removeTail();
        }
        // create a new entry in the cache;
        Node* newEntry = insertNewNode(key, value);
        hashTable[key] = newEntry;

        return;
    }

private:
    void moveToHead(Node* node) {
        if(node == head) {
            return;
        }
        if(node == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        if(node->prev) {
            node->prev->next = node->next;
        }
        if(node->next) { // if not tail
            node->next->prev = node->prev;
        }

        node->prev = nullptr;
        node->next = head;
        if(head) head->prev = node;

        head = node;

        if(!tail) tail = head;
    }

    bool removeTail() {
        Node* prev = tail->prev;
        if(prev) {
            prev->next = nullptr;
        }

        hashTable.erase(tail->key);
        delete tail;

        tail = prev;
        if(tail == nullptr) {
            head = nullptr;
        }

        return true;
    }

    Node* insertNewNode(int key, int value) {
        Node *newEntry = new Node(key, value);

        if(!head) {
            head = newEntry;
            tail = newEntry;
            return newEntry;
        }

        head->prev = newEntry;
        newEntry->next = head;
        head = newEntry;

        return head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
