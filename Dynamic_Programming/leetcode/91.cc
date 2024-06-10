#include "bits/stdc++.h"
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        map<pair<int, int>, int> dp;

        auto rec = [&](int i, string prev, auto &&rec) -> int {
            int toInt = stoi(prev);
            if(toInt <= 0 || toInt > 26)
                return 0;
            if(i >= s.length()) {
                return 1;
            }
            if(dp.count({i, toInt})) {
                return dp[{i, toInt}];
            }
            // include curr char in the prev String;
            int decodeCount = rec(i + 1, prev + s[i], rec);
            // make the curr char the prev string
            prev.clear();
            prev += s[i];
            decodeCount += rec(i + 1, prev, rec);
            return dp[{i, toInt}] = decodeCount;
        };

        string prev = "";
        return rec(1, prev + s[0], rec);
    }
};

