#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int top_bottom(int i, int row, int &n, vector<vector<int>> &mat, vector<vector<int>> &dp) {
        if(i < 0 || i >= n)
            return 1e9;
        if(row == 0)
            return mat[row][i];
        if(dp[row][i] != INT_MAX)
            return dp[row][i];
        int left = mat[row][i] + top_bottom(i - 1, row - 1, n, mat, dp);
        int center = mat[row][i] + top_bottom(i, row - 1, n, mat, dp);
        int right = mat[row][i] + top_bottom(i + 1, row - 1, n, mat, dp);
        return dp[row][i] = min(left, min(center, right));
    };
    
    // * NOT WORKING
    int bottom_top (int n, vector<vector<int>> &mat, vector<vector<int>> &dp) {
        for(int i = 0; i < n; i++) {
            dp[0][i] = mat[0][i];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int l = 1e8;
                int r = 1e8;
                int c = mat[i][j] + dp[i - 1][j];
                if(i - 1 >= 0)
                    l = mat[i][j] + dp[i - 1][j - 1];
                if(i + 1 < n)
                    r = mat[i][j] + dp[i - 1][j + 1];
                dp[i][j] = min(l, min(r, c));
            }
        }
        int minSum = INT_MAX;
        for(int i = 0; i < n; i++) {
            minSum = min(dp[n - 1][i], minSum);
        }
        return minSum;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        // int minSum = INT_MAX;
        // for(int i = 0; i < n; i++) {
        //     minSum = min(minSum, top_bottom(i, n - 1, n, matrix, dp));
        // }
        return bottom_top(n, matrix, dp);
    }
};
