#include "bits/stdc++.h"
#include <map>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

//    *******TLE SOLUTION FOR LEETCODE -> BUT IS A VALID ONE FOR INTERVIEWS*****
//    void solve(vector<string> &ls, queue<vector<string>> &q, unordered_set<string> &words,
//            string &endWord, unordered_set<string> &taken, unordered_set<string> &consideredStrings) {
//        vector<vector<string>> ans;
//        bool endFound = false;
//        for(int i = 0; i < ls.back().length(); i++) {
//            if(endFound)
//                break;
//            string curr = ls.back();
//            for(char ch = 'a'; ch <= 'z'; ch++) {
//                curr[i] = ch;
//                if(taken.count(curr))
//                    continue;
//                if(curr == endWord) {
//                    ls.push_back(curr);
//                    q.push(ls);
//                    ls.pop_back();
//                    endFound = true;
//                    break;
//                }
//                else if(words.count(curr)) {
//                    consideredStrings.insert(curr);
//                    ls.push_back(curr);
//                    ans.push_back(ls);
//                    ls.pop_back();
//                }
//            }
//        }
//        if(!endFound) {
//            for(auto l : ans) {
//                q.push(std::move(l));
//            }
//        }
//        return;
//    }
//
//    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//        vector<vector<string>> res;
//        unordered_set<string>words;
//        for(auto word : wordList) {
//            words.insert(word);
//        }
//        if(!words.count(endWord))
//            return res;
//
//        queue<vector<string>>q;
//        unordered_set<string> taken;
//        q.push(vector<string>(1, beginWord));
//        taken.insert(beginWord);
//        while(!q.empty()) {
//            int size = q.size();
//            unordered_set<string> consideredStrings;
//            while(size--) {
//                vector<string> curr = q.front();
//                q.pop();
//                if(curr.back() == endWord) {
//                    res.push_back(curr);
//                    continue;
//                }
//                solve(curr, q, words, endWord, taken, consideredStrings);
//            }
//            if(!res.empty()) {
//                cout << res.size();
//                break;
//            }
//
//            for(auto str : consideredStrings) {
//                taken.insert(str);
//            }
//        }
//        return res;
//    }
class Solution {
    public:
        vector<vector<string>> ans;
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            map<string, int>level;
            int lvl = 0;
            unordered_set<string> words(wordList.begin(), wordList.end());
            unordered_set<string> visited;
            queue<string>q;
            q.push(beginWord);
            visited.insert(beginWord);
            while(!q.empty()) {
                int size = q.size();
                while(size--) {
                    string word = q.front();
                    q.pop();
                    level[word] = lvl;
                    for(int i = 0; i < word.size(); i++) {
                        string w = word;
                        for(char ch = 'a'; ch <= 'z'; ch++) {
                            w[i] = ch;
                            if(visited.count(w))
                                continue;
                            if(words.count(w)) {
                                q.push(w);
                                visited.insert(w);
                            }
                        }
                    }
                }
                lvl++;
            }
            //dfs on the words from last to first;
            visited.clear();
            visited.insert(endWord);
            dfs({endWord}, beginWord, words, level, visited);
            return ans;
        }

        void dfs(vector<string> wordList, string &beginWord, unordered_set<string> &words, map<string, int> &level, unordered_set<string> visited) {
            string lsW = wordList.back();
            if(level[lsW] == 1) {
                wordList.push_back(beginWord);
                reverse(wordList.begin(), wordList.end());
                ans.push_back(wordList);
                return;
            }
            for(int i = 0; i < lsW.size(); i++) {
                string w = lsW;
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    w[i] = ch;
                    if(visited.count(w))
                        continue;
                    if(words.count(w)) {
                        if(level[lsW] - level[w] == 1) {
                            visited.insert(w);
                            wordList.push_back(w);
                            dfs(wordList, beginWord, words, level, visited);
                            wordList.pop_back();
                        }
                    }
                }
            }
        }
};

