#include "bits/stdc++.h"
#include <unordered_set>
using namespace std;

class Solution {
public:
    unordered_set<int>safeNodes;
    bool dfs(int node, vector<vector<int>>& graph, vector<bool> &visited) {
        if(visited[node])
            return safeNodes.count(node) ? true : false;
        if(graph[node].empty()) {
            safeNodes.insert(node);
            return true;
        }
        visited[node] = true;
        for(auto nbrs : graph[node]) {
            if(!dfs(nbrs, graph, visited)) {
                return false;
            }
        }
        safeNodes.insert(node);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        vector<bool>visited(graph.size(), false);
        for(int i = 0; i < graph.size(); i++) {
            if(dfs(i, graph, visited))
                ans.push_back(i);
        }
        return ans;
    }
};
