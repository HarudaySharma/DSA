#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;
class Solution {
    public:
        int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
            vector<vector<int>> adj(n, vector<int> (n, INT_MAX));
            for (auto it : edges) {
                adj[it[0]][it[1]] = it[2];
                adj[it[1]][it[0]] = it[2];
            }
            for (int i = 0; i < n; i++) adj[i][i] = 0;
            for (int v = 0; v < n; v++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (adj[i][v] == INT_MAX || adj[v][j] == INT_MAX)
                            continue;
                        adj[i][j] = min(adj[i][j], adj[i][v] + adj[v][j]);
                    }
                }
            }

            int maxDist = n;
            int city = -1;
            for (int i = 0; i < n; i++) {
                int count = 0;
                for (int j = 0; j < n; j++) {
                    if (adj[i][j] <= distanceThreshold)
                        count++;
                }

                if (count <= maxDist) {
                    maxDist = count;
                    city = i;
                }
            }
            return city;

        }
};

