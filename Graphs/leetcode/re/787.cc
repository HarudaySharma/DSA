#include <bits/stdc++.h>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int, vector<pair<int, int>>> mp;
        for(auto flight : flights) {
            mp[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> minPrice(n, INT_MAX);
        queue<pair<int, pair<int, int>>> q;
        q.push({k, {src, 0}});
        minPrice[src] = 0;
        while(!q.empty()) {
            int K = q.front().first;
            int currStop = q.front().second.first;
            int price = q.front().second.second;
            q.pop();
            if(K == -1)
                continue;
            for(auto adjs : mp[currStop]) {
                int p = adjs.second;
                int adjFlight = adjs.first;
                if(p + price < minPrice[adjFlight]) {
                    minPrice[adjFlight] = p + price;
                    q.push({K - 1, {adjFlight, minPrice[adjFlight]}});
                }
            }
        }
        return minPrice[dst] == INT_MAX ? -1 : minPrice[dst];
    }
};

