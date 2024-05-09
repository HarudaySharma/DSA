#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int ilndCount;
    vector<vector<bool>> visited;

    Solution () : ilndCount(0){}

    void rec(int i, int j, int &n, int &m, vector<vector<char>>& grid) {
        if(i >= n || i < 0 || j >= m || j < 0 
                || visited[i][j] || grid[i][j] == '0')
            return;
        visited[i][j] = true;
        rec(i - 1, j, n, m, grid);
        rec(i + 1, j, n, m, grid);
        rec(i, j - 1, n, m, grid);
        rec(i, j + 1, n, m, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited.resize(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    ilndCount += 1;
                    rec(i, j, n, m, grid);
                }
            }
        }
        return ilndCount;
    }
};

