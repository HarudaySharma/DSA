#include <bits/stdc++.h>

using namespace std;

class DSU {
private:
    unordered_map<int, int> parent; // as we don't know the total nodes
    unordered_map<int, int> rank; // rank is depecting the number of nodes in a disjoint set (i.e. rank of representative node of ds)

public:
    DSU(vector<vector<int>>& edges) {
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // inital config
            parent[u] = u;
            parent[v] = v;
            rank[u] = 1;
            rank[v] = 1;
        }
    }

    int find(int node) {
        int p = parent[node];
        if(p == node) {
            return p;
        }

        return parent[node] = find(p);
    }

    int unite(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        if(p1 == p2) {
            return false; // already in the same disjoint set.
        }

        if(rank[p1] >= rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else{
            parent[p1] = p2;
            rank[p2] += rank[p1]; // rank is to be added
        }

        return true;
    }

};

class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if(!dsu.unite(u, v)) {
                return edge;
            }
        }

        return edges.back();
    }
};

