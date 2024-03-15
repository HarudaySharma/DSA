#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int top_bottom(int i, int j, vector<vector<int>> &dp) {
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        if(dp[i][j] != -1) 
            return dp[i][j];
        int up = uniquePaths(i - 1, j);
        int left = uniquePaths(i, j - 1);
        dp[i][j] = up + left;
        return  dp[i][j];
    }

    int bottom_top(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0)
                    dp[0][0] = 1;
                else {
                    if(i - 1 >= 0) {
                        dp[i][j] = dp[i-1][j];
                    }
                    if(j - 1 >= 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return top_bottom(m - 1, n - 1, dp);
    }
};
