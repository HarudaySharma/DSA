#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        auto rec = [&](int i, int j, auto &&rec) -> int {
            if(i < 0 || j < 0 || i >= m || j >= n)
                return 0;
            if(i == m - 1 && j == n - 1)
                return 1;
            if(dp[i][j] != -1)
                return dp[i][j];
            int res = rec(i + 1, j, rec);
            res += rec(i, j + 1, rec);
            return dp[i][j] = res;
        };
        return rec(0, 0, rec);
    }
};

