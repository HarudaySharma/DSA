#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalNonObs = 0;

    int countWalks(pair<int, int> point, int n, int m, vector<vector<int>>& grid, int nonObsCount) {
        auto [i, j] = point;

        if(i < 0 || i >= n || j < 0 || j >= m) {
            return 0;
        }
        if(grid[i][j] == -1) {
            return 0;
        }
        if(grid[i][j] == 2) {
            return nonObsCount == totalNonObs;
        }

        if(grid[i][j] == 0) {
            nonObsCount += 1;
        }
        // marking the current cell as {-1} signifying visited
        grid[i][j] = -1;

        int count = 0;
        int delI[] = {-1, 0, 1, 0};
        int delJ[] = {0, 1, 0, -1};
        for(int x = 0; x < 4; x++) {
            count += countWalks({i + delI[x], j + delJ[x]}, n, m, grid, nonObsCount);
        }

        // resetting the cell state.
        grid[i][j] = 0;

        return count;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        //Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.
        // 1 -> start
        // 0 -> non-obstacle
        // -1 -> obstacle
        // 2 -> end;

        // steps:
        // 1. start from the starting point
        // 2. try traversing to all the directions
        // 3. keep the count of all the non-obstacle squares visited till now.

        int n = grid.size();
        int m = grid[0].size();
        pair<int, int> startPoint;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    startPoint = {i, j};
                }
                if(grid[i][j] == 0) {
                    totalNonObs += 1;
                }
            }
        }

        return countWalks(startPoint, n, m, grid, 0);
    }
};

