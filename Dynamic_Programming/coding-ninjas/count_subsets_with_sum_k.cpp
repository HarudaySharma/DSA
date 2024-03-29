#include<bits/stdc++.h>
#include <vector>
using namespace std;

int top_bottom(int i, int k, vector<int> &arr, vector<vector<int>> &dp) {
    if(k == 0)
        return 1;
    if(i == 0)
        return k == arr[i] ? 1 : 0;
    if(dp[i][k] != -1)
        return dp[i][k];
    int count = 0;
    count += top_bottom(i - 1, k, arr, dp);
    if(arr[i] <= k)
        count += top_bottom(i - 1, k - arr[i], arr, dp);
    return dp[i][k] = count;
}

int bottom_up(int n, vector<int> &arr, int k) {
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for(int i = 0; i < n; i++)
        dp[i][0] = 1;
    if(arr[0] <= k)
        dp[0][arr[0]] = 1;
    for(int i = 1; i < n; i++) {
        for(int target = 1; target <= k; target++) {
            int noTake = dp[i - 1][target];
            int take = 0;
            if(arr[i] <= target)
                take = dp[i - 1][target - arr[i]];
            dp[i][target] = noTake + take;
        }
    }
    return dp[n - 1][k];
}

int findWays(vector<int>& arr, int k) {
    // vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1));
    // return top_bottom(arr.size() - 1, k, arr, dp);
    return bottom_up(arr.size(), arr, k);
}

