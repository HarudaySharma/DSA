#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class compare {
    public:
        bool operator() (const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) const {
            return a.first > b.first;
        }
};

class Solution {
public:
    int dist(pair<int, int> a, pair<int, int> b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        map<pair<int, int>, vector<pair<int, pair<int, int>>>> adjList;
        // {x} = [{a, dist}, {b, dist}...]
        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            for(int j = 0; j < points.size(); j++) {
                int _x = points[j][0];
                int _y = points[j][1];
                pair<int, pair<int, int>> nbr;
                nbr.second = {_x, _y};
                nbr.first = dist({x, y}, {_x, _y});
                adjList[{x, y}].push_back(nbr);
            }
        }
        // applying prims algorithm
        set<pair<int, int>> visited;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> pq;
        // starting with any node {{0, 0}, 0}
        pq.push({0, {points[0][0], points[0][1]}});
        int minDist = 0;
        while(!pq.empty()) {
            if(visited.size() == adjList.size())
                return minDist;
            auto val = pq.top();
            pq.pop();
            int dist = val.first;
            pair<int, int> pnt = val.second;
            // mark it visited
            if(visited.count(pnt))
                continue;
            visited.insert(pnt);
            minDist += dist;
            // add all the neighbours of curr point to minHeap
            for(auto pr : adjList[pnt]) {
                pq.push({pr.first, pr.second});
            }
        }
        return minDist;
    }
};

