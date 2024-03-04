#include "bits/stdc++.h"
#include <climits>
#include <stack>
#include <vector>
using namespace std;

class Solution {
    private:
        void topoSort(int i, vector<vector<pair<int,int>>> &adjList, vector<bool> &visited, stack<int> &st) {
            visited[i] = true;
            for(auto it : adjList[i]) {
                if(!visited[it.first])
                    topoSort(it.first, adjList, visited, st);
            }
            st.push(i);
        }

    public:
        vector<int> shorestPath(vector<int> edges[], int V, int E, int src) {
            // do TopoSort of the given graph
            // store the TopoSort path in stack
            vector<vector<pair<int,int>>> adjList(V);
            for(int i = 0; i <  V; i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
                adjList[u].push_back({v, wt});
            }
            // doing the TopoSort;
            vector<bool>visited(V, false);
            stack<int>st;
            for(int i = 0; i < V; i++) {
                if(!visited[i])
                    topoSort(i, adjList, visited, st);
            }
            // make a distance array
            vector<int>dist(V, INT_MAX);
            dist[src] = 0;
            while(!st.empty()) {
                int node = st.top();
                st.pop();
                for(auto adjs : adjList[node]) {
                    int ngbr = adjs.first;
                    int wt = adjs.second;
                    if(dist[node] + wt < dist[ngbr]) {
                        dist[ngbr] = dist[node] + wt;
                    }
                }
            }
            return dist;
        }
};

int main(int argc, char *argv[]) { return 0; }
