#include "bits/stdc++.h"
#include <ios>
#include <vector>
using namespace std; 

class compare {
    public:
        bool operator()(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) const {
            return a.first > b.first;
        }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> pq;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        pq.push({grid[0][0], {0, 0}});
        int leastTime = INT_MIN;
        while(!pq.empty()) {
            int wt = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if(i == n - 1 && j == m - 1)
                return max(leastTime, grid[i][j]);
            if(visited[i][j]) {
                continue;
            }
            leastTime = max(leastTime, wt);
            visited[i][j] = true;
            // pushing all the adjacents
            if(j + 1 < m) {
                pq.push({grid[i][j + 1], {i, j + 1}});
            }
            if(i + 1 < n) {
                pq.push({grid[i + 1][j], {i + 1, j}});
            }
            if(i - 1 >= 0) {
                pq.push({grid[i - 1][j], {i - 1, j}});
            }
            if(j - 1 >= 0) {
                pq.push({grid[i][j - 1], {i, j - 1}});
            }
        }
            
        return leastTime;
    }
};

