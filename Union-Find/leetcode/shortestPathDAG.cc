#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Solution {
  public:
    vector<int> distance;

    void rec(int u, vector<vector<pair<int, int>>>& adjList) {
        for(auto nei : adjList[u]) {
            int wt = nei.second;
            int v = nei.second;
            if(distance[u] + wt < distance[v]) {
                distance[v] = distance[u] + wt;
            }
            rec(v, adjList);
        }

        return;
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        distance.resize(V, INT_MAX);

        vector<vector<pair<int, int>>> adjList(V);
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjList[u].push_back({v, wt});
        }
        distance[0] = 0;

        rec(0, adjList);


        for(auto &vl : distance) {
            if(vl == INT_MAX) {
                vl = -1;
            }
        }

        return distance;
    }
};
