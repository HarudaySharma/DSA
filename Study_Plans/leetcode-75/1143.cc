#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));

        auto rec = [&](int i, int j, string subSeq, auto &&rec) -> int {
            if(i >= text1.size() || j >= text2.size())
                return 0;

            if(dp[i][j] != -1)
                return dp[i][j];

            if(text1[i] == text2[j]) {
                subSeq.push_back(text1[i]);
                return dp[i][j] = rec(i + 1, j + 1, subSeq, rec) + 1;
            }

            dp[i][j] = max(rec(i + 1, j, "", rec),
                    rec(i, j + 1, "", rec));

            return dp[i][j];
        };

        return rec(0, 0, "", rec);
    }

};

