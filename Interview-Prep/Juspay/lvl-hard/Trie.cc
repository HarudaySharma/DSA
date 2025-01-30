#include "bits/stdc++.h"

using namespace std;

class TrieNode {
public:
    bool isTerminal;
    vector<TrieNode*> children;

    TrieNode() {
        isTerminal = false;
        children.resize(26, nullptr); // indexes correspond to the character the node is referring to
    }

    ~TrieNode() {
        deleteNode(this);
    }

private:
    void deleteNode(TrieNode* root) {
        for(auto child : children) {
            if(child) {
                deleteNode(child);
            }
        }

        delete root;
    }

};

//
// A trie (pronounced as "try") or prefix tree is a tree data structure used to
// efficiently store and retrieve keys in a dataset of strings. There are
// various applications of this data structure, such as autocomplete and
// spellchecker.
//
// Implement the Trie class:
//
//     Trie() Initializes the trie object.
//     void insert(String word) Inserts the string word into the trie.
//     boolean search(String word) Returns true if the string word is in the
//     trie (i.e., was inserted before), and false otherwise. boolean
//     startsWith(String prefix) Returns true if there is a previously inserted
//     string word that has the prefix prefix, and false otherwise.
//
class Trie {

private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(string word) {
        if(word.empty()) {
            return;
        }

        auto curr = root;

        for(auto ch : word) {
            int idx = ch - 'a';

            if(!curr->children[idx]) {
                createNode(curr, idx);
            }
            curr = curr->children[idx];
        }

        // curr will point to the last character node
        curr->isTerminal = true;
    }

    bool search(string word) {
        if(word.empty()) {
            return false;
        }

        auto curr = root;
        for(auto ch : word) {
            int idx = ch - 'a';
            if(!curr->children[idx]) {
                return false;
            }

            curr = curr->children[idx];
        }

        return curr->isTerminal;
    }

    bool startsWith(string prefix) {
        if(prefix.empty()) {
            return true;
        }

        auto curr = root;
        for(auto ch : prefix) {
            int idx = ch - 'a';
            if(!curr->children[idx]) {
                return false;
            }

            curr = curr->children[idx];
        }

        return true;
    }

private:
    // creates a trie node and saves it's reference in the parent's children array "idx" (index)
    void createNode(TrieNode* parent, int idx) {
        parent->children[idx] = new TrieNode();
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
