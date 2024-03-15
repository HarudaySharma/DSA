#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int top_bottom(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if(i == 0 && j == 0)
            return grid[0][0];
        if(i < 0 || j < 0)
            return  1e8;
        if(dp[i][j] != -1)
            return dp[i][j];
        int up = grid[i][j] + top_bottom(i - 1, j, grid, dp);
        int left = grid[i][j] + top_bottom(i, j - 1, grid, dp);
        dp[i][j] = min(left, up);
        return dp[i][j];
    }

    int bottom_top(int n, int m, vector<vector<int>>& grid) {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    dp[0][0] = grid[0][0];
                }
                else {
                    int left = INT_MAX;
                    int up = INT_MAX;
                    if(i - 1 >= 0)
                        up = dp[i - 1][j];
                    if(j - 1 >= 0)
                        left = dp[i][j - 1];
                    dp[i][j] = grid[i][j] + min(left, up);
                }

            }
        }
        return dp[n - 1][m - 1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return bottom_top(n, m,  grid);
    }
};
