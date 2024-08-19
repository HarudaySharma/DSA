#include <bits/stdc++.h>
#include <memory>
#include <vector>
using namespace std;

class Trie {
    private:
        struct TrieNode {
            TrieNode *childNodes[26];
            bool terminal;

            TrieNode() {
                terminal = false;
                for (auto &node : childNodes)
                    node = nullptr;
            }
        };

        TrieNode *root;

    public:
        Trie() {
            root = new TrieNode(); 
        }

        ~Trie() {
            auto deleteNodes = [](TrieNode *curr, auto &&deleteNodes) {
                if(!curr)
                    return;

                for(auto node : curr->childNodes) {
                    deleteNodes(node, deleteNodes);
                }

                delete curr;
            };

            deleteNodes(root, deleteNodes);
        }
        void insert(string word) {
            TrieNode *curr = root;
            for (int i = 0; i < word.length(); i++) { // apple
                int ch = word[i] - 'a';
                if (curr->childNodes[ch] == nullptr)
                    curr->childNodes[ch] = new TrieNode();
                curr = curr->childNodes[ch];
            }
            curr->terminal = true;
        }

        bool search(string word) {
            auto *curr = root;

            for (int i = 0; i < word.length(); i++) {
                char ch = word[i] - 'a';
                if (curr->childNodes[ch] == nullptr)
                    return false;
                curr = curr->childNodes[ch];
            }
            return curr->terminal;
        }

        vector<string> getFirstNSuggestion(string prefix, int n) {
            vector<string> res;
            auto prefixNode = getPrefixNode(prefix);
            fillWithWords(prefixNode, res, prefix, n);

            return res;
        }

    private:
        TrieNode* getPrefixNode(string &prefix) {

            auto rec = [&](TrieNode *curr, int i, auto &&rec) -> TrieNode* {
                if(!curr || i > prefix.size())
                    return nullptr;

                if(i == prefix.size())
                    return curr;

                const int ch = prefix[i] - 'a';

                return rec(curr->childNodes[ch], i + 1, rec);
            };

            return rec(root, 0, rec);
        }

        void fillWithWords(TrieNode *curr, vector<string> &acc, string word, int &limit) {
            if (!curr || acc.size() == limit)
                return;

            if (curr->terminal) {
                acc.push_back(word);
            }

            for (char ch = 'a'; ch <= 'z'; ch++) {
                if(acc.size() == limit) 
                    break;
                fillWithWords(curr->childNodes[ch - 'a'], acc, word + ch, limit);
            }

            return;
        }
};

class Solution {
    public:
        vector<vector<string>> usingSorting(vector<string> &products, string searchWord) {
            sort(products.begin(), products.end());

            vector<vector<string>> res;
            string prefix;
            int l = 0;
            int r = products.size() - 1;

            auto getFirstNSuggestion = [&](string word, int n) -> vector<string> {
                vector<string> match;

                while (l <= r && !(products[l].substr(0, word.size()) == word)) {
                    l++;
                }
                while (l <= r && !(products[r].substr(0, word.size()) == word)) {
                    r--;
                }

                int i = 0;
                while (l + i <= r && match.size() != n) {
                    if (l + i <= r)
                        match.push_back(products[l + (i++)]);
                }

                return match;
            };

            for (int i = 0; i < searchWord.length(); i++) {
                prefix.push_back(searchWord[i]);
                res.push_back(getFirstNSuggestion(prefix, 3));
            }

            return res;
        }

        vector<vector<string>> usingTries(vector<string> &products, string searchWord) {
            Trie *tr = new Trie();
            for(auto product : products) {
                tr->insert(product);
            }

            vector<vector<string>> res;
            string prefix;
            for(auto &ch : searchWord) {
                prefix.push_back(ch);
                res.push_back(tr->getFirstNSuggestion(prefix, 3));
            }
            return res;
        }

        vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
            //return usingSorting(products, searchWord);
            return usingTries(products, searchWord); // is giving memory limit excedded on leetcode
        }
};
