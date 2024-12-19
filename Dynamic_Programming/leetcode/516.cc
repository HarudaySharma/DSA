#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            dp[i][i] = 1; // Base Case
        }

        // fill the upper triangle of the dp matrix diognally -
        // dp[i][j + x]
        // [0, 1], [1, 2], [2, 3], [3, 4], [4, 5] // x = 1
        // [0, 2], [1, 3], [2, 4], [3, 5] // x = 2
        for(int x = 1; x < n; x++) {
            for(int i = 0; i < n; i++) {
                int j = i + x;
                if(j >= n) {
                    continue;
                }
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

