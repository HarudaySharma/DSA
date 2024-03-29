#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0)
            return {0};
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        for(int i = 2; i <= n;) {
            int nextOffset = i * 2;
            int offset = i++;
            dp.push_back(1);
            while(i < nextOffset && i <= n) {
                // 3 => 1 + dp[1] => 2
                dp.push_back(1 + dp[i - offset]);
                i++;
            }
        }
        return dp;
    }
};
