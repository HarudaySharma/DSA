#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> visited;
    bool noCycle(int i, vector<int> *adjList, int parent) {
            if(visited[i])
                return false;
            visited[i] = true;
            if(adjList[i].empty())
                return true;
            for(auto curr : adjList[i]) {
                if(curr != parent && !noCycle(curr, adjList, i)) {
                    return false;
                }
            }
            return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adjList[n];
        visited.resize(n, false);
        for(auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        if(!noCycle(0, adjList, -1))
            return false;
        for(auto el : visited) {
            if(el == false)
                return false;
        }
        return true;
    }
};

