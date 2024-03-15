#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int top_bottom(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp) {
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0 || obstacleGrid[i][j] == 1)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int up = top_bottom(i - 1, j, obstacleGrid, dp);
        int left = top_bottom(i, j - 1, obstacleGrid, dp);
        return dp[i][j] = up + left;
    }

    int bottom_top(int n, int m, vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0)
                    dp[0][0] = 1;
                else {
                    if(i - 1 >= 0 && obstacleGrid[i - 1][j] != 1)
                        dp[i][j] = dp[i - 1][j];
                    if(j - 1 >= 0 && obstacleGrid[i][j - 1] != 1)
                        dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[n - 1][m - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
            return 0;
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return top_bottom(n - 1, m - 1, obstacleGrid, dp);
        return bottom_top(n, m, obstacleGrid);
    }
};
