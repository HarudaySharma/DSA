#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void BFS(queue<pair<int, int>> &q, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
            const int maxRow = grid.size() - 1;
            const int maxCol = grid[0].size() - 1;
            const int r[]{-1, 0, 1, 0};
            const int c[]{0, 1, 0, -1};
            while (!q.empty()) {
                auto curr = q.front();
                q.pop();
                for (int x = 0; x < 4; x++) {
                    const int row = curr.first + r[x];
                    const int col = curr.second + c[x];
                    if (row <= maxRow && row >= 0 && col <= maxCol && col >= 0 &&
                            !visited[row][col]) {
                        if (grid[row][col] == 1) {
                            q.push({row, col});
                        }
                        visited[row][col] = true;
                    }
                }
            }
        }

        int numEnclaves(vector<vector<int>> &grid) {
            vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
            queue<pair<int, int>> q;
            int dir = 1;
            while (dir <= 4) {
                // first row
                if (dir == 1) {
                    int i = 0;
                    int j = 0;
                    while (j < grid[i].size()) {
                        if (grid[i][j] == 1) {
                            q.push({i, j});
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
                        if (grid[i][j] == 1) {
                            q.push({i, j});
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
                        if (grid[i][j] == 1) {
                            q.push({i, j});
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
                        if (grid[i][j] == 1) {
                            q.push({i, j});
                        }
                        visited[i][j] = true;
                        i++;
                    }
                }
                dir++;
            }
            BFS(q, grid, visited);
            int count = 0;
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[i].size(); j++) {
                    if(!visited[i][j] && grid[i][j] == 1)
                        count++;
                }
            }
            return count;
        }
};
