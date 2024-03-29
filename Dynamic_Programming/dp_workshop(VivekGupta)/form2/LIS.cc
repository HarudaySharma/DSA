#include <climits>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> dp;
        int rec(int lvl, vector<int> &arr) {
            // pruning / base case
            if(lvl < 0)
                return 0;
            // cache check
            if(dp[lvl] != -1)
                return dp[lvl];
            //compute
            int ans = 1;
            for(int prev_taken = 0; prev_taken < lvl; prev_taken++) {
                if(arr[prev_taken] < arr[lvl])
                    ans = max(ans, 1 + rec(prev_taken, arr));
            }
            // save and return
            return dp[lvl] = ans;
        }

        int longestIncreasingSubsequence(vector<int> arr) {
            dp.resize(arr.size(), -1);
            int bestLIS = INT_MIN;
            for(int i = 0; i < arr.size(); i++)
                bestLIS = max(bestLIS, rec(i, arr));
            return bestLIS;
        }
};

int main (int argc, char *argv[]) {
    return 0;
}
