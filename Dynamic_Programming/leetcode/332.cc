#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
    public:
        // Using 2D dp
        int coinChange(vector<int>& coins, int amount) {
            vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

            auto rec = [&](int i, int amnt, auto &&rec) -> int {
                if(i == 0)
                    return amnt % coins[i] == 0 ? int(amnt/coins[0]) : 1e9;

                if(dp[i][amnt] != -1)
                    return dp[i][amnt];

                // don't use the current coin
                int notTake = rec(i - 1, amnt, rec);
                // consider taking the curr coin
                int take =  1e9;
                if(coins[i] <= amnt) {
                    take = 1 + rec(i, amnt - coins[i], rec);
                }
                return dp[i][amnt] = min(take, notTake);
            };

            int minCoins = rec(coins.size() - 1, amount, rec);
            return minCoins == 1e9 ? -1 : minCoins;
        }

        // 1D DP
        int rec(vector<int>& coins, int amt,vector<int>& dp){
            if(amt==0) return 0;
            if(amt<0) return 1e9;
            if(dp[amt]!=-1) return dp[amt];
            int minCoins=1e9;
            for(int i=0;i<coins.size();i++){
                int ans=rec(coins,amt-coins[i],dp);
                if(ans!=1e9){
                    minCoins=min(minCoins,1+ans);
                }
            }
            return dp[amt]=minCoins;
        }

        int CoinChange(vector<int>& coins, int amount) {
            int n=coins.size();
            vector<int> dp(amount+1,-1);
            int ans= rec(coins,amount,dp);
            if(ans==1e9)return -1;
            return ans;
        }
};
