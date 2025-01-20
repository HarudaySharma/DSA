#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n, m;

    int DFS(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, vector<vector<int>> &dp) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return 1e9;
        }
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (visited[i][j]) {
            return 1e9;
        }

        visited[i][j] = true;
        int cost = INT_MAX;
        // 1 -> right | 2 -> left | 3 -> bottom | 4 -> top
        int delI[]{0, 0, 0, 1, -1};
        int delJ[]{0, 1, -1, 0, 0};
        for (int x = 1; x <= 4; x++) {
            if (x == grid[i][j]) {
                cost = min(cost, DFS(i + delI[x], j + delJ[x], grid, visited, dp));
            } else {
                cost = min(cost, 1 + DFS(i + delI[x], j + delJ[x], grid, visited, dp));
            }
        }
        visited[i][j] = false;

        return dp[i][j] = cost;
    }

    int dijkstra(int src_i, int src_j, int dest_i, int dest_j, vector<vector<int>> &grid) {
        // {cost, {i. j}}
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        pq.push({0, {src_i, src_j}}); // initial config
        while (!pq.empty()) {
            int cost = pq.top().first;
            int i = pq.top().second[0];
            int j = pq.top().second[1];
            pq.pop();

            if (i < 0 || i >= n || j < 0 || j >= m) {
                continue;
            }
            if (visited[i][j]) {
                continue;
            }
            if (i == n - 1 && j == m - 1) {
                return cost;
            }

            visited[i][j] = true;

            // check all the four directions
            int delI[]{0, 0, 0, 1, -1};
            int delJ[]{0, 1, -1, 0, 0};
            for (int x = 1; x <= 4; x++) {
                int _i = i + delI[x];
                int _j = j + delJ[x];

                if (x == grid[i][j]) {
                    pq.push({cost, {_i, _j}});
                } else {
                    pq.push({cost + 1, {_i, _j}});
                }
            }
        }

        return -1;
    }

    int minCost(vector<vector<int>> &grid) {
        // vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        // vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(),
        // ^ for DFS ^

        n = grid.size();
        m = grid[0].size();

        return dijkstra(0, 0, n - 1, m - 1, grid);
    }
};

