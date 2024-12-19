#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));

        auto BFS = [&](queue<pair<int, int>> &q) {
            vector<pair<int, int>> directions{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

            while(!q.empty()) {
                int size = q.size();
                while(size--) {
                    auto [i, j] = q.front();
                    q.pop();

                    if(i < 0 || i >= n || j < 0 || j >= m) {
                        continue;
                    }
                    for(auto [dx, dy] : directions) {
                        int x = i + dx;
                        int y = j + dy;
                        if(x < 0 || x >= n || y < 0 || y >= m) {
                            continue;
                        }
                        if(res[i][j] + 1 < res[x][y]) {
                            res[x][y] = res[i][j] + 1;
                            q.push({x, y});
                        }
                    }
                }
            }
        };

        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // get all the 0's and run multi source bfs starting from them
                if(mat[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        BFS(q);

        return res;
    }
};

