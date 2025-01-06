#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S) {
        vector<int> dist(V, 1e8);

        dist[S] = 0;
        for (int i = 1; i <= V - 1; i++) {
            for (auto edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // negative cycle check:
        //  the distance b/w nodes will still decrease even after V - 1 iterations
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }

        return dist;
    }
};
