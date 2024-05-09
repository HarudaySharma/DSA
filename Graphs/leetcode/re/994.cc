#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || grid[i][j] == 2)
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int units = -1;
        int delI[4]{-1, 0, 1, 0};
        int delJ[4]{0, 1, 0, -1};
        queue<pair<int, int>>  q;
        // getting all the rotted ones
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        // doing BFS on the rotted oranges;
        while (!q.empty()) {
            int size = q.size();
            while(size--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int a = 0; a < 4; a++) {
                    int x = i + delI[a];
                    int y = j + delJ[a];
                    if(isValid(x, y, n, m, grid)) {
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
            units++;
        }
        int zeroCount = 0;
        for(auto row : grid) {
            for(auto el : row) {
                if(el == 1)
                    return -1;
                if(el == 0)
                    zeroCount += 1;
            }
        }
        return zeroCount == n * m ? 0 : units;
    }
};
