#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPr = INT_MIN;
        for(int buy = 0, sell = 0; sell < prices.size(); sell++) {
            while(prices[buy] > prices[sell])
                buy++;
            maxPr = max(maxPr, prices[sell] - prices[buy]);
        }
    }
};
