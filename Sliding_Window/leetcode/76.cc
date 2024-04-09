#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
    public:
        string minWindow(string s, string t) {
            map<char, int> hash_t;
            map<char, int> hash_s;
            int need = 0;
            for(auto ch : t) {
                hash_t[ch] += 1;
                need++;
            }
            int have = 0;
            int l = 0, r = 0;
            int startIndex = 0;
            int minLen = INT_MAX;
            while(r < s.size()) {
                char ch = s[r];
                hash_s[ch] += 1;
                if(hash_t.count(ch) && hash_s[ch] <= hash_t[ch])
                    have++;
                while(have >= need) {
                    if(r - l + 1 < minLen) {
                        minLen = r - l + 1;
                        startIndex = l;
                    }
                    char ch = s[l++];
                    hash_s[ch] -= 1;
                    if(hash_s[ch] < hash_t[ch])
                        have -= 1;
                }
                r++;
            }
            return minLen == INT_MAX ?  "" : s.substr(startIndex, minLen);
        }
};

