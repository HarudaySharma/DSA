#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i, int j, string txt1, string txt2, int n, int m) {
        if(i >= n || j >= m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        // compute
        int ans = 0;
        ans = max(ans, rec(i + 1, j, txt1, txt2, n, m));
        ans = max(ans, rec(i, j + 1, txt1, txt2, n, m));
        if(txt1[i] == txt2[j])
            ans = max(ans, 1 + rec(i + 1, j + 1, txt1, txt2, n, m));
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp.resize(n, vector<int>(m, -1));
        return rec(0, 0, text1, text2, n, m);
    }
};
