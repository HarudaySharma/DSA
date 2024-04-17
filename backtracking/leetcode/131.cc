#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    bool isPalindrome(string s, int i, int j) {
        if (s.empty()) {
            return false;
        }
        while (i < j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }

public:
    vector<vector<string>> res;
    void rec(string s, int i, vector<string> ans) {
        if(i >= s.length()){
            res.push_back(ans);
            return;
        }
        for(int j = i + 1; j < s.length(); j++) {
            if(isPalindrome(s, i, j)) {
                ans.push_back(s.substr(i, j - i + 1));
                rec(s, j + 1, ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        rec(s, 0, {});
        return res;
    }
};

