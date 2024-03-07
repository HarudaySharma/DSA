#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    // @return 
    // true if last cell can be reached
    bool checkAdjacents(int i, int j, queue<pair<pair<int, int>, int>> &q, int n, int m, int &count, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        const int delRow[] {-1, -1, 0, 1, 1, 1, 0, -1};
        const int delCol[] {0, 1, 1, 1, 0, -1, -1, -1};
        for(int x = 0; x < 8; x++) {
            int I = i + delRow[x];
            int J = j + delCol[x];
            if(I == n - 1 && J == m - 1)
                return true;
            if(I < 0 || I >= n || J < 0 || J >= m || visited[I][J])
                continue;
            visited[I][J] = true;
            if(grid[I][J] == 0)
                q.push({{I, J}, count + 1});
        }
        return false;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
            return -1;
        if(n == 1 && m == 1) {
            return 1;
        }
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>>q;
        q.push({{0, 0}, 1});
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int i = curr.first.first;
            int j = curr.first.second;
            int count = curr.second;
            if(checkAdjacents(i, j, q, n, m, count, grid, visited)) {
                return count + 1;
            }
        }
        return -1;
    }
};
