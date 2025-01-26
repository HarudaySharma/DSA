#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> parent;

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        parent.resize(n, vector<string>(m, ""));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    parent[i][j] = getKey(i, j);
                }
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    dfs(i, j, parent[i][j], grid, visited, n, m);
                }
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++)  {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    if(parent[i][j] == getKey(i, j)) { // the cell representing an island found.
                        count += 1;
                    }
                }
            }
        }

        return count;
    }

private:
    void dfs(int i, int j, string prevParent, vector<vector<char>> &grid, vector<vector<bool>> &visited, int N, int M) {
        if(i < 0 || i >= N || j < 0 || j >= M) {
            return;
        }
        if(grid[i][j] == '0') {
            return;
        }
        if(visited[i][j]) {
            return;
        }

        visited[i][j] = true;
        parent[i][j] = prevParent;

        dfs(i + 1, j, parent[i][j], grid, visited, N, M);
        dfs(i - 1, j, parent[i][j], grid, visited, N, M);
        dfs(i, j - 1, parent[i][j], grid, visited, N, M);
        dfs(i, j + 1, parent[i][j], grid, visited, N, M);

        return;
    }

    string getKey(int i, int j) {
        return to_string(i) + "" + to_string(j);
    }
};

