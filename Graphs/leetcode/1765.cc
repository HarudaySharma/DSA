#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        // 0 -> land, 1 -> water
        // height to each cell using
        // - h >= 0
        // - h (water cell) = 0
        // - h diff (two adj cells) <= 1
        // assign heights such that ->
        //      maximum height in matrix is as max as possible.
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> height(n, vector<int>(m, -1));

        queue<pair<int, int>> q; // {i, j}
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j]) {
                    q.push({i, j});
                }
            }

        }

        // multi source BFS
        int currH = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [i, j] = q.front();
                q.pop();

                if(i < 0 || j < 0 || j >= m || i >= n) {
                    continue;
                }
                if(height[i][j] != -1) { // height is already computed
                    continue;
                }

                height[i][j] = currH;
                q.push({i + 1, j});
                q.push({i - 1, j});
                q.push({i, j + 1});
                q.push({i, j - 1});
            }
            currH++;
        }

        return height;
    }
};

