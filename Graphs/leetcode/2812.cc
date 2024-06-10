#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;


class Solution {

    class compare {
        public:
            bool operator() (const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) const {
                return a.first < b.first;
            }
    };

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return 0;

        // applying a multi-source bfs from all the theifs;
        // will get the dist b/w all the 0's to their closest 1.
        auto getClosestDist = [&]() -> vector<vector<int>> {
            queue<pair<int, int>> q;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == 1){
                        q.push({i, j});
                    }
                }
            }
            vector<vector<int>> distMat(n, vector<int>(m, 0));
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            int x = 0;
            while(!q.empty()){
                int size = q.size();
                while(size--) {
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();
                    if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j])
                        continue;
                    // check all the neighbours.
                    distMat[i][j] = x;
                    visited[i][j] = true;
                    q.push({i + 1, j});
                    q.push({i, j + 1});
                    q.push({i - 1, j});
                    q.push({i, j - 1});
                }
                x++;
            }
            return distMat;
        };

        auto distMat = getClosestDist();
        for(auto row : distMat) {
            for(auto cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }

        // getting the path from (0,0) to (n-1, m-1) 
        // having the maximum dist b/w any path cell and 1 be the least;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> pq;
        pq.push({distMat[0][0], {0, 0}});

        while(!pq.empty()) {
            int dist = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || distMat[i][j] == 0) {
                continue;
            }
            if(i == n - 1 && j == m - 1)
                return dist;

            visited[i][j] = true;
            // adjacents
            if(i + 1 < n) {
                pq.push({min(dist, distMat[i + 1][j]), {i + 1, j}});
            }
            if(j + 1 < m) {
                pq.push({min(dist, distMat[i][j + 1]), {i, j + 1}});
            }
            if(j - 1 >= 0) {
                pq.push({min(dist, distMat[i][j - 1]), {i, j - 1}});
            }
            if(i - 1 >= 0) {
                pq.push({min(dist, distMat[i - 1][j]), {i - 1, j}});
            }
        }
        return 0;
    }
};
