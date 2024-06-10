#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        auto rec = [&](int i, int target, auto &&rec) {
            if(target == 0) {
                return 1;
            }
            if(i >= coins.size() || target < 0) {
                return 0; 
            }
            if(dp[i][target] != -1)
                return dp[i][target];

            int nt = rec(i + 1, target, rec);
            int tk = 0;
            if(target >= coins[i])
                tk = rec(i, target - coins[i], rec);
            return dp[i][target] = nt + tk;
        };

        return rec(0, amount, rec);
    }
};

