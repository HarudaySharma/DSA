#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        map<int, int> dp;

        auto tri = [&](int n, auto &&tri) {
            if(n == 0)
                return 0;
            if(n == 1 || n == 2)
                return 1;
            
            if(dp.count(n))
                return dp[n];

            return dp[n] = tri(n - 1, tri) + tri(n - 2, tri) + tri(n - 3, tri);
        };
        
        return tri(n, tri);
    }
};
