#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // SOLUTION - 1 (More Efficient)
      bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length(), -1);

        auto rec = [&](int i, auto &&rec) -> int {
            if(i == s.length())
                return true;
            if(dp[i] != -1) {
                return dp[i];
            }

            bool ans = false;
            for(auto word : wordDict) {
                if(word == s.substr(i, word.length())) {
                    if(ans == true)
                        break;
                    ans = rec(i + word.length(), rec);
                }
            }
            return dp[i] = ans;
        };
        
        return rec(0, rec);
      }
      
    /* 
     * SOLUTION - 2
      bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto str : wordDict) {
            dict.insert(str);
        }
        
        map<pair<int, string>, int> dp;
        
        auto rec = [&](int i, string subSr, auto &&rec) -> int {
            if(i == s.length()) {
                return 0;
            }
            if(dp.count({i, subSr})) {
                return dp[{i, subSr}];
            }

            subSr.push_back(s[i]);
            int case1 = 0;
            if(dict.count(subSr)) {
                case1 += subSr.length() + rec(i + 1, "", rec);
            }
            int case2 = rec(i + 1, subSr, rec);
            return dp[{i, subSr}] = max(case2, case1);
        };

        string subSr = "";
        int charsCovered = rec(0, subSr, rec);
        return charsCovered == s.length();
    } */

};
