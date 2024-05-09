#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> visited;
    void DFS(int i, vector<int> *adjList) {
            if(visited[i])
                return;
            visited[i] = true;
            for(auto curr : adjList[i]) {
                if(!visited[curr])
                    DFS(curr, adjList);
            }
            return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adjList[n];
        visited.resize(n, false);
        for(auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        int componentCount = 0;
        for(int i = 0; i < n; i++) { 
            if(!visited[i]) {
                componentCount += 1;
                DFS(i, adjList);
            }
        }
        return componentCount;
    }
};


