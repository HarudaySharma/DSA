#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
            // create a adjList
            vector<vector<pair<int, double>>> adjList(n);
            int x = 0;
            for(auto edge : edges) {
                adjList[edge[0]].push_back({edge[1], succProb[x]});
                adjList[edge[1]].push_back({edge[0], succProb[x++]});
            }

            // Dijkstra's algorithm
            vector<double> dist(n, -1e9);
            vector<bool> visited(n, false);
            priority_queue<pair<double, int>> pq;

            dist[start_node] = 1;
            pq.push({1, start_node}); 
            while(!pq.empty()) {
                auto v = pq.top().second;
                auto w = pq.top().first;
                pq.pop();

                if(visited[v])
                    continue;
                visited[v] = true;

                for(auto ad : adjList[v]) {
                    auto nei = ad.first;
                    auto wt = ad.second;
                    if(w * wt > dist[nei]) {
                        dist[nei] = w * wt;
                        pq.push({dist[nei], nei});
                    }
                }
            }

            return dist[end_node] == -1e9 ? 0 : dist[end_node];
        }
};

