#include<bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    bool BFS(int n, vector<vector<int>>& graph, vector<int> &colour) {
        queue<pair<int, vector<int>>> q;
        colour[n] = 0;
        q.push({0, graph[n]});
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            for(int adj : node.second) {
                if(colour[adj] == colour[node.first])
                    return false;
                if(colour[adj] == -1) {
                    colour[adj] = colour[node.first] == 0 ? 1 : 0;
                    q.push({adj, graph[adj]});
                }
            }
        }
        return true;
    }

    bool DFS(int n, vector<vector<int>>& graph, vector<int> &colour, int prevColor) {
        if(colour[n] != -1) 
            return prevColor == colour[n] ? false : true;

        colour[n] = prevColor == 0 ? 1 : 0;
        for(auto adj : graph[n]) {
            if(!DFS(adj, graph, colour, colour[n]))
                    return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colour(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++) {
            if(colour[i] == -1) {
                if(!DFS(i, graph, colour, -1))
                    return false;
            }
        }
        return true;
    }
};
