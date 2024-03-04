#include "bits/stdc++.h"
#include <queue>
#include <vector>
using namespace std;

class Solution {
    public:
        void BFS(queue<pair<pair<int, int>, int>>&q, vector<vector<int>>& mat, vector<vector<bool>>& visited, vector<vector<int>>& distance) {
            const int maxRow = mat.size() - 1;
            const int maxCol = mat[0].size() - 1;
            const int r[] {-1, 0, 1, 0};
            const int c[] {0, 1, 0, -1};
            while(!q.empty()) {
                auto curr = q.front();
                q.pop();
                for(int x = 0; x < 4; x++) {
                    const int row = curr.first.first + r[x];
                    const int col = curr.first.second + c[x];
                    if(row <= maxRow && row >= 0 && col <= maxCol && col >= 0 && !visited[row][col]) {
                        if(mat[row][col] == 1) {
                            visited[row][col] = true;
                            q.push({{row, col}, curr.second + 1});
                        }
                        else {
                            visited[row][col] = true;
                            distance[row][col] = 0;
                        }
                    }
                }
                distance[curr.first.first][curr.first.second] = curr.second;
            }
        }
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            vector<vector<bool>>visited;
            vector<vector<int>>distance;
            queue<pair<pair<int, int>, int>>q;
            for(int i = 0; i < mat.size(); i++) {
                vector<bool> row(mat[i].size(), false);
                vector<int> dist(mat[i].size(), 0);
                visited.push_back(row);
                distance.push_back(dist);
                for(int j = 0; j < mat[i].size(); j++) {
                    if(mat[i][j] == 0) {
                        visited[i][j] = true;
                        q.push({{i, j}, 0});
                    }
                }
            }
            BFS(q, mat, visited, distance);
            return distance;
        }
};
