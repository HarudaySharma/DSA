#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<int, int> dp;
    int rec(int i, vector<int> &cost, int n) {
        if(i > n) {
            return INT_MAX;
        }
        if(i == n) {
            return 0;
        }
        if(dp.count(i)) {
            return dp[i];
        }
        int minCost = min(rec(i + 1, cost, n),
            rec(i + 2, cost, n));
        dp[i] = minCost + cost[i];
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return min(rec(0, cost, cost.size()), rec(1, cost, cost.size()));
    }
};

