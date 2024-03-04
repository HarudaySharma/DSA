#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
    public:
        bool rotAdjacent(pair<int, int>pos, vector<vector<int>> &grid, char dir) {
            switch (dir) {
                case 't':
                    return pos.first - 1 >= 0 && grid[pos.first - 1][pos.second] == 1;
                case 'b':
                    return pos.first + 1 < grid.size() && grid[pos.first + 1][pos.second] == 1;
                case 'l':
                    return pos.second - 1 >= 0 && grid[pos.first][pos.second - 1] == 1;
                case 'r':
                    return pos.second + 1 < grid[0].size() && grid[pos.first][pos.second + 1] == 1;
            }
            return false;
        }

        int orangesRotting(vector<vector<int>>& grid) {
            int minMinutes = -1;
            int rottenCount = 0;
            queue<pair<int,int>>rottenOranges;
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[i].size(); j++) {
                    if(grid[i][j] == 2) {
                        rottenOranges.push({i, j});
                    }
                    if(grid[i][j] == 0) {
                        // considering blank cells as rotten 
                        // for future calculations
                        rottenCount++;
                    }
                }
            }
            while(!rottenOranges.empty()) {
                int size = rottenOranges.size();
                rottenCount += size;
                while(size--) {
                    pair<int, int>pos = rottenOranges.front();
                    rottenOranges.pop();
                    if(rotAdjacent(pos, grid, 't')) {
                        grid[pos.first - 1][pos.second] = 2;
                        rottenOranges.push({pos.first - 1, pos.second});
                    }
                    if(rotAdjacent(pos, grid, 'b')) {
                        grid[pos.first + 1][pos.second] = 2;
                        rottenOranges.push({pos.first + 1, pos.second});
                    }
                    if(rotAdjacent(pos, grid, 'l')) {
                        grid[pos.first][pos.second - 1] = 2;
                        rottenOranges.push({pos.first, pos.second - 1});
                    }
                    if(rotAdjacent(pos, grid, 'r')) {
                        grid[pos.first][pos.second + 1] = 2;
                        rottenOranges.push({pos.first, pos.second + 1});
                    }
                }
                minMinutes += 1;
            }
            return rottenCount == grid.size() * grid[0].size() ? minMinutes == -1 ? 0 : minMinutes : -1;

        }
};

