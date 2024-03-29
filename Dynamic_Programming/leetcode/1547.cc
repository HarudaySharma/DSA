#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> dp;
        int rec(int l, int r, vector<int> &cuts) {
            //basecase
            if(l + 1 == r)
                return 0;

            // cache check
            if(dp[l][r] != -1)
                return dp[l][r];

            //compute
            int ans = 1e9;
            int stickSize = cuts[r] - cuts[l];
            for(int p = l + 1; p < r; p++) {
                ans = min(ans, stickSize + rec(l, p, cuts) + rec(p, r, cuts));
            }
            return dp[l][r] = ans;
        }
        int minCost(int n, vector<int>& cuts) {
            cuts.push_back(0);
            cuts.push_back(n);
            sort(cuts.begin(), cuts.end());
            dp.resize(cuts.size(), vector<int>(cuts.size(), -1));
            return rec(0, cuts.size() - 1, cuts);
        }
};
