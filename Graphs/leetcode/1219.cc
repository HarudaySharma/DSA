#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxGold = 0;
        map<pair<int, int>, int> dp;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        auto rec = [&](int i, int j, auto &&rec) -> int {
            if(i < 0 || j < 0 || j >= m || i >= n || grid[i][j] == 0)
                return 0;
            if(visited[i][j]) {
                return 0;
            }
            visited[i][j] = true;
            int maxG = rec(i + 1, j, rec);
            maxG = max(maxG, rec(i, j + 1, rec));
            maxG = max(maxG, rec(i - 1, j, rec));
            maxG = max(maxG, rec(i, j - 1, rec));
            maxG += grid[i][j];
            visited[i][j] = false;
            return maxG;
        };

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) {
                    maxGold = max(rec(i, j, rec), maxGold);
                }
            }
        }
        return maxGold;
    }
};

