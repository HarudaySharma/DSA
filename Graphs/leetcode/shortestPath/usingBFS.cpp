#include "bits/stdc++.h"
#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    private:

    public:
        vector<int> shorestPath(vector<int> adj[], int V, int E, int src) {
            // make a distance array
            vector<int>dist(V, INT_MAX);
            dist[src] = 0;
            queue<int>q;
            q.push(src);
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                for(auto nbr : adj[node]) {
                    if(dist[nbr] > dist[node] + 1) {
                        dist[nbr] = dist[node] + 1;
                        q.push(nbr);
                    }
                }
            }
            return dist;
        }
};

int main(int argc, char *argv[]) { return 0; }
