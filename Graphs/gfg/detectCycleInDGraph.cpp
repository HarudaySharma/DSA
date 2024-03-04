#include "bits/stdc++.h"
using namespace std;

class Solution {
    public:
        // Function to detect cycle in a directed graph.
        bool dfs(vector<int> *adj, const int &i, vector<int> &visited) {
            if(visited[i] == 1) 
                return false;

            if(visited[i] == 2)
                return true;

            if(adj[i].empty())
                return true;

            visited[i] = 1;
            for(auto x : adj[i]) {
                if(!dfs(adj, x, visited))
                    return false;
            }
            visited[i] = 2;
            return true;
        }

        bool isCyclic(int V, vector<int> adj[]) {
            vector<int> visited(V, 0);
            for(int i = 0; i < V; i++) {
                if(!dfs(adj, i, visited))
                    return true;
            }
            return false;
        }
};
