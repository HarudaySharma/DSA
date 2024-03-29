#include "bits/stdc++.h"
#include <vector>
using namespace std;


vector<int>dp;
int rec(int x) {
    if(x == 0)
        return 0;

    if(dp[x] != -1)
        return dp[x];

    int ans = 0;
    for(int m = 0; (1 << m) <= x; m++) {
        if(rec(x - (1 << m) == 0)){
            ans = 1;
            break;
        }
    }
    return dp[x] = ans;
}

void solve() {
    int x = 3;
    dp.resize(x + 1, -1);
    rec(x);
    
}
int main (int argc, char *argv[]) {
    return 0;
}
