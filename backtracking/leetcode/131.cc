#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    map<pair<int, int>, bool> mp;

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;

        auto rec = [&](int i, vector<string> &res, auto &&rec) {
            if(i >= s.size()) {
                ans.push_back(res);
                return;
            }

            for(int j = i; j < s.length(); j++) {
                if(isPalindrome(s, i, j)) {
                    mp[{i, j}] = true;
                    res.push_back(s.substr(i, j - i + 1));
                    rec(j + 1, res, rec);
                    res.pop_back();
                } else {
                    mp[{i, j}] = false;
                }
            }
            return;
        };

        vector<string> res;
        rec(0, res, rec);

        return ans;
    }

private:
    bool isPalindrome(string s, int i, int j) {
        while(i < j) {
            if(mp.count({i, j})) {
                return mp[{i, j}];
            }
            if(s[i++] != s[j--]) {
                return false;
            }
        }

        return true;
    }

};



