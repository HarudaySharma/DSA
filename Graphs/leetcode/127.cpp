#include "bits/stdc++.h"
#include <iterator>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool solve(int i, string curr, queue<string> &q, unordered_set<string> &words, string &endWord, unordered_set<string> &taken) {
        for(char ch = 'a'; ch <= 'z'; ch++) {
            curr[i] = ch;
            if(taken.count(curr))
                continue;
            if(curr == endWord)
                return true;
            if(words.count(curr)) {
                q.push(curr);
                taken.insert(curr);
            }
        }
        return false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int lvl = 0;
        unordered_set<string>words;
        for(auto word : wordList) {
            words.insert(word);
        }
        if(!words.count(endWord))
            return 0;

        queue<string>q;
        unordered_set<string> taken;
        q.push(beginWord);
        taken.insert(beginWord);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                string curr = q.front();
                q.pop();
                if(curr == endWord)
                    return lvl;
                for(int i = 0; i < curr.length(); i++) {
                    if(solve(i, curr, q, words, endWord, taken))
                        return lvl + 1;
                }
            }
            lvl++;
        }
        return 0;
    }
};
