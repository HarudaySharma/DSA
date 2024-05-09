#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    int find(int node) {
        int p = parent[node];
        while(p != parent[p]) {
            // modifying the parents
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool u(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);
        if(p1 == p2)
            return false;
        int rank1 = rank[p1];
        int rank2 = rank[p2];
        if(rank1 >= rank2) {
            rank[parent[p1]] += 1;
            parent[p2] = parent[p1];
        }
        else {
            rank[parent[p2]] += 1;
            parent[p1] = parent[p2];
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 1; i < edges.size() + 1; i++) {
            rank[i] = 1;
            parent[i] = i;
        }
        for(auto edge : edges) {
            if(!u(edge[0], edge[1]))
                return edge;
        }
        return edges.back();
    }
};

