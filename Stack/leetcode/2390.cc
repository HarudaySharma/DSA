#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string res;
        for(auto ch : s) {
            if(ch == '*') {
                res.pop_back();
            }
            else
                res.push_back(ch);
        }
        return res;
    }
};

