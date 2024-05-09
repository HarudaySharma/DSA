#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<bool>> visited;

    int rec(int i, int j, int &n, int &m, vector<vector<int>>& grid) {
        if(i >= n || i < 0 || j >= m || j < 0 
                || visited[i][j] || grid[i][j] == 0)
            return 0;
        int count = 1;
        visited[i][j] = true;
        count += rec(i - 1, j, n, m, grid);
        count += rec(i + 1, j, n, m, grid);
        count += rec(i, j - 1, n, m, grid);
        count += rec(i, j + 1, n, m, grid);
        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        visited.resize(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    maxArea = max(maxArea, rec(i, j, n, m, grid));
                }
            }
        }
        return maxArea;
    }
};

