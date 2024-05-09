#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<bool>> visited;
        bool isValidBlock(int i, int j, int &n, int &m, vector<vector<int>>& grid) {
            if(i >= n || i < 0 || j >= m || j < 0 || visited[i][j] || grid[i][j] == -1)
                return false;
            return true;
        }

        void islandsAndTreasure(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            queue<pair<int, int>> q;
            visited.resize(n, vector<bool>(m, false));
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == 0) {
                        q.push({i, j});
                        visited[i][j] = true;
                    }
                }
            }
            int dist = 0;
            while(!q.empty()) {
                int size = q.size();
                while(size--) {
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();
                    grid[i][j] = dist;
                    if(isValidBlock(i , j + 1, n, m, grid)) {
                        q.push({i, j + 1});
                        visited[i][j + 1] = true;
                    }
                    if(isValidBlock(i - 1 , j, n, m, grid)) {
                        q.push({i - 1, j});
                        visited[i - 1][j] = true;
                    }
                    if(isValidBlock(i + 1 , j, n, m, grid)) {
                        q.push({i + 1, j});
                        visited[i + 1][j] = true;
                    }
                    if(isValidBlock(i, j - 1, n, m, grid)) {
                        q.push({i, j - 1});
                        visited[i][j - 1] = true;
                    }
                }
                dist++;
            }
        }
};

