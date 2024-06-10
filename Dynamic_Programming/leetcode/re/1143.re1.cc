#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        auto rec = [&](int i, int j, auto &&rec) -> int {
            if(i >= n || j >= m) {
                return 0;
            }
            if(dp[i][j] == -1)
                return dp[i][j];

            int res = rec(i + 1, j, rec);
            res = max(res, rec(i, j + 1, rec));
            if(text1[i] == text2[j]){
                res = max(res, 1 + rec(i + 1, j + 1, rec));
            }
            return dp[i][j] = res;
        };
        return rec(0, 0, rec);
    }
};

