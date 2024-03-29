#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> dp;
        // as the values at indices can be negative (-1 also)
        vector<vector<bool>> done;

        int rec(int r, int c, vector<vector<int>> &arr) {
            //pruning
            if(r < 0 || c < 0)
                return -1e8;

            // base case
            if(r == 0 && c == 0)
                return arr[0][0];

            //cache check
            if(done[r][c])
                return dp[r][c];

            // compute 
            int ans = rec(r - 1, c, arr);
            ans = max(ans, rec(r, c - 1, arr));

            // save and return
            done[r][c] = true;
            dp[r][c] = ans + arr[r][c];
            return dp[r][c];
        }

        int maxSum(vector<vector<int>> arr) {
            dp.resize(arr.size(), vector<int>(arr[0].size(), -1));
            done.resize(arr.size(), vector<bool>(arr[0].size(), false));
            return rec(arr.size() - 1, arr[0].size() - 1, arr);
        }
};

int main (int argc, char *argv[]) {
    return 0;
}
