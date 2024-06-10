#include "bits/stdc++.h"
#include <climits>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(int r, int c, int rows, int cols,
            vector<vector<int>>& heights, vector<vector<int>> &minEffort,
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>&pq) {
        const int delR[]{-1, 0, 1, 0};
        const int delC[]{0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int x = r + delR[i];
            int y = c + delC[i];
            if(x < 0 || x >= rows || y < 0 || y >= cols)
                continue;
            int diff = abs(heights[r][c] - heights[x][y]);
            int effort = max(diff, minEffort[r][c]);
            if(effort < minEffort[x][y]) {
                minEffort[x][y] = effort;
                pq.push({effort, {x, y}});
            }
        }
        return;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> minEffort(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        minEffort[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int mxH = pq.top().first;
            pq.pop();
            if(r == n - 1 && c == m - 1)
                return minEffort[r][c];
            // check the adjacents
            helper(r, c, n, m, heights, minEffort, pq);
        }
        return -1;
    }
};

int main (int argc, char *argv[]) {
    vector<vector<int>>grid {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    Solution s;
    s.minimumEffortPath(grid);
    return 0;
}
