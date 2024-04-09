#include <bits/stdc++.h>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    public:
        queue<pair<string, int>> *considered;
        unordered_set<int> consideredIdx;
        int matchSubStr(vector<string> &words, vector<int> &idxs, string target) {
            for (auto i : idxs) {
                if (words[i] == target) {
                    return i;
                }
            }
            return -1;
        }
        vector<int> matchFirstChar(vector<string> &words, char ch) {
            vector<int> matches;
            for (int i = 0; i < words.size(); i++) {
                if (consideredIdx.count(i))
                    continue;
                if (words[i][0] == ch)
                    matches.push_back(i);
            }
            return matches;
        }
        vector<int> findSubstring(string s, vector<string> &words) {
            int subLen = words.front().size();
            vector<int> res;
            for(int i = 0; i < subLen; i++) {
                int r = i;
                consideredIdx.clear();
                considered = new queue<pair<string, int>>;
                int l = i;
                // "wordgoodgoodgoodbestword"
                // ["word","good","best","word"]
                while (r < s.size()) {
                    if (considered->size() == words.size()) {
                        res.push_back(l);
                        consideredIdx.erase(considered->front().second);
                        considered->pop();
                        l += subLen;
                        continue;
                    }
                    vector<int> idxs = matchFirstChar(words, s.at(r));
                    string subStr = s.substr(r, subLen);
                    int foundIdx = matchSubStr(words, idxs, subStr);
                    if (foundIdx != -1) {
                        consideredIdx.insert(foundIdx);
                        considered->push({subStr, foundIdx});
                        r += subLen;
                    } else {
                        if(!consideredIdx.empty()) {
                            consideredIdx.erase(considered->front().second);
                            considered->pop();
                            l += subLen;
                        }else {
                            r+= subLen;
                            l = r;
                        }
                    }
                }
                if (considered->size() == words.size()) {
                    res.push_back(l);
                }
                delete considered;
            }
            return res;
        }
};

