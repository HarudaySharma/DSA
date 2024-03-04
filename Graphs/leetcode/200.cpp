#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    const int r[4]{-1, 0, 1, 0};
    const int c[4]{0, 1, 0, -1};

    void DFS(int i, int j, vector<vector<char>>& grid, int &n, int &m, vector<vector<bool>> &visited) {
        if(visited[i][j])
            return;
        visited[i][j] = true;
        for (int x = 0; x < 4; x++) {
            const int row = i + r[x];
            const int col = j + c[x];
            if (row < n && row >= 0 && col < m && col >= 0 &&
                    !visited[row][col] && grid[i][j] == '1') {
                DFS(row, col, grid, n, m, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ilndCount = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    ilndCount += 1;
                    DFS(i, j, grid, n, m, visited);
                }
            }
        }
        return ilndCount;
    }
};
