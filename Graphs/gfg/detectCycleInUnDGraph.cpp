#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool dfs(const int curr, const int parent, vector<int> *adj, vector<int> &visited) {
            if(visited[curr] == 1) 
                return false;

            if(!adj[curr].size())
                return true;

            if (visited[curr] == 2) 
                return true;

            visited[curr] = 1;
            for(auto adjacent : adj[curr]) {
                if(adjacent != parent) {
                    if(!dfs(adjacent, curr, adj, visited))
                        return false;
                }
            }
            visited[curr] = 2;
            return true;
        }
        
        bool isCycle(int V, vector<int> adj[]) {
            vector<int> visited(V, 0);
            for(int i = 0; i < V; i++) {
                if(!dfs(i, -1, adj, visited))
                        return true;
            }
            return false;
        }
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;

}
