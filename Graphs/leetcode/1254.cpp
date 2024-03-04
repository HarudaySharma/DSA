#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    // 0 -> land, 1 -> water
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited)  {
        if(i < 0 || i >= grid.size() 
                || j < 0 || j >= grid[i].size()) {
            return;
        }
        if(visited[i][j] || grid[i][j] == 1)
            return;
        visited[i][j] = true;
        int delR[] { -1, 0, 1, 0 };
        int delC[] { 0, 1, 0, -1 };
        for(int x = 0; x < 4; x++) {
            dfs(i + delR[x], j + delC[x], grid, visited);
        }
        return;
    }

    void markBorder0s(vector<vector<int>> &grid, vector<vector<bool>> &visited) {
            int dir = 1;
            while (dir <= 4) {
                // first row
                if (dir == 1) {
                    int i = 0;
                    int j = 0;
                    while (j < grid[i].size()) {
                        if(grid[i][j] == 0) {
                            dfs(i, j, grid, visited);
                        }
                        visited[i][j] = true;
                        j++;
                    }
                }
                // first col
                if (dir == 2) {
                    int i = 1;
                    int j = 0;
                    while (i < grid.size()) {
                        if (grid[i][j] == 0) {
                            dfs(i, j, grid, visited);
                        }
                        visited[i][j] = true;
                        i++;
                    }
                }
                // last row
                if (dir == 3) {
                    int i = grid.size() - 1;
                    int j = 1;
                    while (j < grid[i].size()) {
                        if (grid[i][j] == 0) {
                            dfs(i, j, grid, visited);
                        }
                        visited[i][j] = true;
                        j++;
                    }
                }
                // last column
                if (dir == 4) {
                    int i = 1;
                    int j = grid[0].size() - 1;
                    while (i < grid.size() - 1) {
                        if (grid[i][j] == 0) {
                            dfs(i, j, grid, visited);
                        }
                        visited[i][j] = true;
                        i++;
                    }
                }
                dir++;
            }
    }

    int closedIsland(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        markBorder0s(grid, visited);
        // make all the border 0's and there connecting 0's visited
        int ilndCount = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0 && !visited[i][j]) {
                    ilndCount += 1;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return ilndCount;
    }
};
