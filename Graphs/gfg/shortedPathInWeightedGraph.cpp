//{ Driver Code Starts
#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
            vector<pair<int, int>> adjList[n + 1];
            for(auto e : edges) {
                adjList[e[0]].push_back({e[1], e[2]});
                adjList[e[1]].push_back({e[0], e[2]});
            }

            vector<int>dist(n + 1, INT_MAX);
            vector<int>predecessor(n + 1, 1);
            dist[1] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
            pq.push({0, 1});
            while(!pq.empty()) {
                auto top = pq.top();
                pq.pop();
                int u = top.second;
                int dt = top.first;
                for(auto ad : adjList[u]) {
                    int wt = ad.second;
                    int v = ad.first;
                    if(dt + wt < dist[v]) {
                        predecessor[v] = u;
                        dist[v] = dt + wt;
                        pq.push({dist[v], v});
                    }
                }
            }
            if(dist[n] == INT_MAX) 
                return {-1};
            
            // get the predecessor of current end node and repeat
            vector<int>res;
            stack<int>path;
            res.push_back(dist[n]);
            while(predecessor[n] != n) {
                path.push(n);
                n = predecessor[n];
            }
            path.push(1);
            while(!path.empty()) {
                res.push_back(path.top());
                path.pop();
            }
            return res;
        }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int,int>,int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0],edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1],edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans=0;
        for(int i=2;i<res.size();i++)
        {
            ans+=mp[{res[i],res[i-1]}];
        }
        if(res.size()==1) ans=res[0];
        cout<<ans<<endl;
    }
}

// } Driver Code Ends
