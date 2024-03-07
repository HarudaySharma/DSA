#include <bits/stdc++.h>
#include <memory>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int src, int dest, int k, int price, vector<vector<pair<int, int>>> &adjList, vector<int> &minPrice) {
        if(minPrice[src] != 0 && minPrice[src] < price)
            return;
        minPrice[src] = price;
        if(src == dest || k == -1)
            return;
        cout << src << " : " << minPrice[src] << endl;
        for(auto adj : adjList[src]) {
            int node = adj.first;
            int p = adj.second;
            dfs(node, dest, k - 1, p + price, adjList, minPrice);
        }
        minPrice[src] -= price;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // creating adjList;
        vector<vector<pair<int, int>>> adjList(n, vector<pair<int, int>>());
        vector<int> minPrice(n, 0);
        minPrice[src] = -1;
        for(auto f : flights) {
            adjList[f[0]].push_back({f[1], f[2]});
        }

        for(auto adj : adjList[src]) {
            dfs(adj.first, dst, k - 1, adj.second, adjList, minPrice);
        }

        for(int i = 0; i < n; i++) {
            for(auto adjs : adjList[i]) {
                cout << i << "=>" << adjs.first << endl;
            }
            cout << "----" << endl;

        }
        return minPrice[dst] == 0 ? -1 : minPrice[dst];
    }
};
