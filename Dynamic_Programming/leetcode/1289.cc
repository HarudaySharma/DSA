#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int findMinPath(int i, int j, int &n, int &m, vector<vector<int>>& grid) {
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return 0;
        }
        if(dp[i][j] != INT_MIN)
            return dp[i][j];
        // check for all the elements in the row;
        int smallestPath = INT_MAX;
        for(int J = 0; J < m; J++) {
            if(J == j) continue;
            smallestPath = min(smallestPath, findMinPath(i + 1, J, n, m, grid));
        }
        if(smallestPath == INT_MAX)
            smallestPath = 0;
        smallestPath += grid[i][j];
        return dp[i][j] = smallestPath;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n, vector<int>(m, INT_MIN));
        int minPath = INT_MAX;
        for(int j = 0; j < m; j++) {
            minPath = min(minPath, findMinPath(0, j, n, m, grid));
        }
        return minPath;
    }
};

