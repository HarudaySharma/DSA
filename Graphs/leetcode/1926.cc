#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;

        auto isExit = [&](int i, int j) -> bool {
            return (i == rows - 1 || i == 0 || j == cols - 1 || j == 0);
        };

        auto addAllAdjs = [&](int i, int j) {
            if(i + 1 < rows)
                q.push({i + 1, j});
            if(j + 1 < cols)
                q.push({i, j + 1});
            if(j - 1 >= 0)
                q.push({i, j - 1});
            if(i - 1 >= 0)
                q.push({i - 1, j});
        };

        addAllAdjs(entrance[0], entrance[1]);
        visited[entrance[0]][entrance[1]] = true;
        int lvl = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if(visited[i][j] || maze[i][j] == '+')
                    continue;
                if(isExit(i, j)) 
                    return lvl;

                visited[i][j] = true;
                addAllAdjs(i, j);
            }
            lvl++;
        }
        return -1;
    }
};

