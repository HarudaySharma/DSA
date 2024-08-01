#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        vector<vector<int>> adjList;

        for(int i = 0; i < isConnected.size(); i++) {
            vector<int> neighs;
            for(int j = 0; j < isConnected[i].size(); j++) {
                if(j == i || isConnected[i][j] == 0)
                    continue;
                neighs.push_back(j);
            }
            adjList.push_back(neighs);
        }

        int totalProvinces = 0;
        for(int i = 0; i < adjList.size(); i++) {
            if(!visited[i]) {
                totalProvinces += 1;
                DFS(i, adjList, visited);
            }
        }
        return totalProvinces;
    }

    void DFS(int i, vector<vector<int>> &adjList, vector<bool> &visited) {
        if(visited[i])
            return;

        visited[i] = true;
        for(auto neigh : adjList[i]) {
            DFS(neigh, adjList, visited);
        }
        return;
    }
};
