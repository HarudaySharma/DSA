//{ Driver Code Starts
#include<bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        void dfs(int i, vector<int> *adj, stack<int> &nodes, vector<bool> &visited) {
            if(visited[i] || !adj[i].size())
                return;

            visited[i] = true;
            for(auto ad : adj[i]) {
                dfs(ad, adj, nodes, visited);
            }
            nodes.push(i);
            return;
        }

        int dfs(int i, vector<int> *adj, vector<bool>visited) {
            if(visited[i] || !adj[i].size())
                return 0;

            visited[i] = true;
            int count = 0;
            for(auto ad : adj[i]) {
               count += dfs(ad, adj, visited) + 1;
            }
            return count;
        }

        int findMotherVertex(int V, vector<int>adj[]) {
            vector<bool> visited(V, false);
            stack<int>nodes;
            
            for(int i = 0; i < V; i++) {
                if(!visited[i])
                    dfs(i, adj, nodes, visited);
            }
            int res = nodes.top();
            for(auto x : visited)
                x = false;

            return dfs(res, adj, visited) >= V - 1 ? res : -1;
        }

};

//{ Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        Solution obj;
        int ans = obj.findMotherVertex(V, adj);
        cout << ans <<"\n";
    }
    return 0;
}
// } Driver Code Ends(
