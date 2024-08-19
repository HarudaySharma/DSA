#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // stock -> buy || sell
        // choices => buy or sell 
        // dp[day, s|b]

        map<pair<int, int>, int> dp;
        // return profit
        auto rec = [&](int i, bool mustSell, auto &&rec) -> int {
            if(i >= prices.size())
                return 0;
            
            if(dp.count({i, mustSell}))
                return dp[{i, mustSell}];
            
            // at the time of sell the transaction fee is charged
            if(mustSell) {
                // no buy
                // sell at curr day or sell in future
                // sell
                dp[{i, mustSell}] = (prices[i] - fee) + rec(i + 1, false, rec);
                // not sell
                dp[{i, mustSell}] = max(rec(i + 1, true, rec), dp[{i, mustSell}]);

                return dp[{i, mustSell}];
            }

            // buy
            dp[{i, mustSell}] = -prices[i] + rec(i + 1, true, rec);
            // not Buy
            dp[{i, mustSell}] = max(rec(i + 1, false, rec), dp[{i, false}]);

            return dp[{i, mustSell}];
        };

        return rec(0, false, rec);
    }
};

