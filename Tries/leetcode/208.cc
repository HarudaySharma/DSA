#include <bits/stdc++.h>
using namespace std;

class Trie {
    private:
        struct TrieNode {
            TrieNode* childNodes[26];
            bool terminal;

            TrieNode() {
                terminal = false;
                for(auto &node : childNodes)
                    node = nullptr;
            }

        };

        TrieNode *root;

    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(string word) {
            TrieNode *curr = root;
            for(int i = 0; i < word.length(); i++) {// apple
                char ch = word[i] - 'a';
                if(curr->childNodes[ch] == nullptr)
                    curr->childNodes[ch] = new TrieNode();
                curr = curr->childNodes[ch];
            }
            curr->terminal = true;
        }

        bool search(string word) {
            auto *curr = root;

            for(int i = 0; i < word.length(); i++) {
                char ch = word[i] - 'a';
                if(curr->childNodes[ch] == nullptr)
                    return false;
                curr = curr->childNodes[ch];
            }
            return curr->terminal;
        }

        bool startsWith(string prefix) {
            auto *curr = root;

            for(int i = 0; i < prefix.length(); i++) {
                char ch = prefix[i] - 'a';
                if(curr->childNodes[ch] == nullptr)
                    return false;
                curr = curr->childNodes[ch];
            }
            return true;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

