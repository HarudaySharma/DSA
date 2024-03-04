#include "bits/stdc++.h"
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adjList;
        if(n == 1)
            return {0};

        adjList.resize(n);
        for(auto &edge : edges) {
            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]);
        }
        queue<int> q;
        for(int i = 0; i < adjList.size(); i++) {
            if(adjList[i].size() == 1)
                q.push(i);
        }
        while (n > 2) {
            int size = q.size();
            // removing the leaf nodes
            n = n - size;
            for(int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                for(auto &neighbour : adjList[node]) {
                    adjList[neighbour].erase(node);
                    if(adjList[neighbour].size() == 1)
                        q.push(neighbour);
                }
            }
        }
        vector<int>res;
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
