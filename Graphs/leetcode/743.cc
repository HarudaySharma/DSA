#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class compare {
    public:
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
            return a.first > b.first;
        }
};

class Solution {
    public:
        int networkDelayTime(vector<vector<int>> &times, int n, int k) {
            // adjList
            vector<vector<pair<int, int>>> adjList(n + 1);
            for (auto pr : times) {
                adjList[pr[0]].push_back({pr[2], pr[1]});
            }
            // applying dijkstra's for minimum distance
            // from K to all other points.
            unordered_set<int> visited;
            priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
            pq.push({0, k});
            int maxDist = INT_MIN;
            while (!pq.empty()) {
                int u = pq.top().second;
                int t = pq.top().first;
                pq.pop();
                if (visited.count(u))
                    continue;
                maxDist = max(maxDist, t);
                visited.insert(u);
                for (auto &nbr : adjList[u]) {
                    int &v = nbr.second;
                    int &tt = nbr.first;
                    if (!visited.count(v)) {
                        tt += t;
                        pq.push(nbr);
                    }
                }
            }
            return visited.size() == n ? maxDist : -1;
        }
};

