#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n, vector<pair<int, int>>());
        for(auto f : flights) {
            adjList[f[0]].push_back({f[1], f[2]});
        }

        queue<pair<int, pair<int, int>>>q;
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;
        q.push({k, {src, 0}});
        while(!q.empty()) {
            int stops = q.front().first;
            int curr = q.front().second.first;
            int d = q.front().second.second;
            q.pop();
            if(stops == -1) {
                continue;
            }
            for(auto adj : adjList[curr]) {
                int distance = d + adj.second;
                if(distance < dist[adj.first]) {
                    dist[adj.first] = distance;
                    q.push({stops - 1, {adj.first, distance}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
