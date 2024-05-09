#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
    public:
        unordered_set<string> wordLs;
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> visited;
            for(auto word : wordList) {
                wordLs.insert(word);
            }
            if(!wordLs.count(endWord))
                return 0;
            queue<string> q;
            q.push(beginWord);
            int lvl = 1;
            while(!q.empty()) {
                int size = q.size();
                while(size--) {
                    string currWord = q.front();
                    q.pop();
                    if(currWord == endWord) {
                        return lvl;
                    }
                    if(visited.count(currWord))
                        continue;
                    visited.insert(currWord);
                    for(auto &ch : currWord) {
                        char orgCh = ch;
                        for(int i = 0; i < 26; i++) {
                            ch = 'a' + i;
                            if(wordLs.count(currWord)) {
                                q.push(currWord);
                            }
                        }
                        ch = orgCh;
                    }
                }
                lvl++;
            }
            return 0;
        }
};

