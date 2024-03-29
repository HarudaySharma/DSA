#include<bits/stdc++.h>
#include <vector>
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
            for(int p = l + 1; p <= r - 1; p++) {
                ans = min(ans, cuts[r] - cuts[l] + rec(l, p, cuts) + rec(p, r, cuts));
            }
            return dp[l][r] = ans;
        }
        int rodcut(vector<int> &cuts, int n) {
            dp.resize(n, vector<int>(n, -1));
            return rec(0, n, cuts);
        }
};

int main (int argc, char *argv[]) {
    return 0;
}
