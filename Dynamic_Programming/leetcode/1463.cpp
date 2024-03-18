#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int top_bottom(int i, int j1, int j2, int &n, int &m, vector<vector<int>>& grid,vector<vector<vector<int>>> &dp) {
        if(i >= n || i < 0 || j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) {
            return -1e8;
        }
        if(i == n - 1) {
            if(j1 == j2)
                return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int mx = INT_MIN;
        int delj[]{-1, 0, 1};
        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                if(j1 == j2)
                    mx = max(mx, grid[i][j1] + top_bottom(i + 1, j1 + delj[x], j2 + delj[y], n, m, grid, dp));
                else {
                    mx = max(mx, grid[i][j1] + grid[i][j2] + top_bottom(i + 1, j1 + delj[x], j2 + delj[y], n, m, grid, dp));
                }
            }
        }
        return dp[i][j1][j2] = mx;
    }

    int bottom_top(vector<vector<int>>& grid, int n, int m) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                if(j1 == j2) 
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                else
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
        int delj[]{-1, 0, 1};
        for(int i = n - 2; i >= 0; i--) {
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {
                    int mx = INT_MIN;
                    for(int x = 0; x < 3; x++) {
                        for(int y = 0; y < 3; y++) {
                            int val = 0;
                            if(j1 == j2)
                                val += grid[i][j1];
                            else
                                val += grid[i][j1] + grid[i][j2];
                            int delj1 = j1 + delj[x];
                            int delj2 = j2 + delj[y];
                            if(delj1 < 0 || delj1 >= m || delj2 < 0 || delj2 >= m)
                                val += -1e8;
                            else
                             val += dp[i + 1][delj1][delj2];
                            mx = max(val, mx);
                        }
                    }
                    dp[i][j1][j2] = mx;
                }
            }
        }
        return dp[0][0][m - 1];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // // dp[r][c][c]
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        // return top_bottom(0, 0, m -1, n, m, grid, dp);
        return bottom_top(grid, n, m);
    }
};
