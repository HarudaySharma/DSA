#include <bits/stdc++.h>
#include <functional>

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // start with the boundary land cells
        // mark all the connected cells to them and keep the count of such cells.
        // at last subtract the computed count and the zero count from the total cell count.
        // why BFS multi-source?
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int boundaryLandCells = 0;

        auto BFS = [&](int i, int j) {
            queue<pair<int, int>> q;

            q.push({i, j});
            while(!q.empty()) {
                int size = q.size();
                while(size--) {
                    auto [i, j] = q.front();
                    q.pop();

                    if(i >= n || i < 0 || j >= m || j < 0) {
                        continue;
                    }
                    if(visited[i][j]) {
                        continue;
                    }
                    if(grid[i][j] == 0) {
                        continue;
                    }

                    boundaryLandCells += 1;
                    visited[i][j] = true;

                    q.push({i + 1, j});
                    q.push({i - 1, j});
                    q.push({i, j + 1});
                    q.push({i, j - 1});
                }
            }
        };

        // check the boundary cells only
        for(int i = 0; i < n; i++) {
            // top down left
            if(grid[i][0] == 1) {
                BFS(i, 0);
            }
            // top down right
            if(grid[i][m - 1] == 1) {
                BFS(i, m - 1);
            }
        }
        for(int j = 0; j < m; j++) {
            // left to right top
            if(grid[0][j] == 1) {
                BFS(0, j);
            }
            // left right bottom
            if(grid[n - 1][j] == 1) {
                BFS(n - 1, j);
            }
        }

        // calculate the number of water cells
        int waterCells = 0;
        for(auto row : grid) {
            for(auto cell : row) {
                if(cell == 0)
                    waterCells += 1;
            }
        }

        return (n * m) - (waterCells + boundaryLandCells);
    }
};

