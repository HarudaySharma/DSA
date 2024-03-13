#include<bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
	public:

    vector <int> usingSet(int V, vector<vector<int>> adj[], int S) {
        set<pair<int, int>>st;
        vector<int>dist(V, INT_MAX);
        dist[S] = 0;
        st.insert({dist[S], S});
        while(!st.empty()) {
            auto top = *st.begin();
            st.erase(st.begin());
            int d = top.first;
            int u = top.second;
            for(auto ad : adj[u]) {
                int v = ad[0];
                int wt = ad[1];
                if(d + wt < dist[v]) {
                    if(dist[v] != INT_MAX)
                        st.erase({dist[v], v});
                    dist[v] = d + wt;
                    st.insert({dist[v], v});
                }
            }
        }
        return dist;
    }

    vector <int> usingMinHeap(int V, vector<vector<int>> adj[], int S) {
        vector<int>dist(V, INT_MAX);
        dist[S] = 0;
        //pair => {dist, node}
        //will store the elements in descending order
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;
        pq.push({dist[S], S});
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int u = top.second;
            int d = top.first;
            for(auto ad : adj[u]) {
                int v = ad[0];
                int wt = ad[1];
                if(d + wt < dist[v]) {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // usingMinHeap(V, adj, S);
        return usingSet(V, adj, S);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

