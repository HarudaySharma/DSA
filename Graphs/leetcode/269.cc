#include <bits/stdc++.h>
#include <queue>
#include <unordered_set>
using namespace std;

// NOT DONE
class Solution {
public:
    string res;
    map<char, unordered_set<char>> adjList;
    map<char, unordered_set<char>> adjListRev;

    void topoSort(queue<char> &q) {
        while (!q.empty()) {
            char node = q.front();
            res.push_back(node);
            q.pop();
            // removing this node from all its parents;
            for(auto parent : adjListRev[node]) {
                adjList[parent].erase(node);
                if(adjList[parent].empty()) {
                    q.push(parent);
                }
            }
            adjListRev.clear();
        }
        return;
    }

    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        for(int i = n - 1; i >= 0; i--) {
            string word1 = words[i];
            for(int j = i - 1; j >= 0; j--) {
                int x = 0; int y = 0;
                string word2 = words[j];
                if(word1.length() < word2.length() && word2.substr(0, word1.length()) == word1) {
                    return "";
                }
                while(x < word1.length() && y < word2.length()){
                    if (word1[x] != word2[y]) {
                        if (adjListRev[word1[x]].count(word2[y])) {
                            return "";
                        }
                        adjList[word1[x]].insert(word2[y]);
                        adjListRev[word2[y]].insert(word1[x]);
                    }
                    x++, y++;
                }
            }
        }
        // topological sorting
        // get all the leaf nodes;
        queue<char> q;
        for(auto pr: adjList) {
            if(pr.second.empty()) {
                q.push(pr.first);
            }
        }
        topoSort(q);
        return res;
    }
};
