#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n, m;

    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int maxFishes = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j] != 0) { // not land cell
                    int fishes = dfs(i, j, grid, visited);
                    maxFishes = max(maxFishes, fishes);
                }
            }
        }

        return maxFishes;
    }

private:

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &visited) {
        if(i < 0 || i >= n || j < 0 || j >= m) { // out of bounds
            return 0;
        }
        if(grid[i][j] == 0) { // land cell
            return 0;
        }
        if(visited[i][j]) {
            return 0;
        }

        visited[i][j] = true;

        int fishes = grid[i][j]; // current water cell
        fishes += dfs(i + 1, j, grid, visited);
        fishes += dfs(i, j + 1, grid, visited);
        fishes += dfs(i, j - 1, grid, visited);
        fishes += dfs(i - 1, j, grid, visited);

        return fishes;
    }
};

