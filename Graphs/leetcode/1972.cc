#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_set<int>> adjList;
    unordered_set<int> visited;
    bool dfs(int source, unordered_set<int> &neighbours, int &destination) {
        if(visited.count(source))
            return false;
        if(source == destination)
            return true;
        visited.insert(source);
        for(auto neighbour : neighbours) {
            if(dfs(neighbour, adjList[neighbour], destination))
                return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(auto edge : edges) {
            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]);
        }
        return dfs(source, adjList[source], destination);
    }
};

