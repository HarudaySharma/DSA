#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));

        auto rec = [&](int i, bool B, auto &&rec) -> int {
            if(i >= prices.size())
                return 0;
            int j = B ? 0 : 1;
            if(dp[i][j] != -1)
                return dp[i][j];
            int res = 0;
            if(B) {
                // buy || cooldown
                res = max(-prices[i] + rec(i + 1, false, rec), rec(i + 1, true, rec));
            }
            else {
                // sell || cooldown
                res = max(rec(i + 2, true, rec) + prices[i], rec(i + 1, false, rec));
            }
            return dp[i][j] = res;
        };

        return rec(0, true, rec);
    }
};

