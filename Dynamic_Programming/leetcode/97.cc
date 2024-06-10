#include <bits/stdc++.h>
#include <sstream>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())
            return false;
        map<string, bool> dp;

        auto rec = [&](int i1, int i2, int i3, auto &&rec) {
            // base case
            if(i3 == s3.size())
                return i1 == s1.length() && i2 == s2.length();
            // cache check
            stringstream ss;
            ss << i1 << "*" << i2 << "*" << i3;
            string key = ss.str();
            if(dp.count(key)) {
                return dp[key];
            }
            // edge cases
            if(i1 == s1.length()){
                return dp[key] = s2[i2] == s3[i3] ? rec(i1, i2 + 1, i3 + 1, rec) : false;
            }
            if(i2 == s2.length()){
                return dp[key] = s1[i1] == s3[i3] ? rec(i1 + 1, i2, i3 + 1, rec) : false;
            }
            // transition
            bool fromS1, fromS2;
            if(s1[i1] == s3[i3]) {
                fromS1 = rec(i1 + 1, i2, i3 + 1, rec);
            }
            if(s2[i2] == s3[i3]) {
                fromS2 = rec(i1, i2 + 1, i3 + 1, rec);
            }

            return dp[key] = fromS1 || fromS2;
        };

        return rec(0, 0, 0, rec);
    }
};

