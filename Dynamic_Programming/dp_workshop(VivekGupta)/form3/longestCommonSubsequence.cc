#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> dp;
        // return LCS of a[i .... n] & b[j ... m]
        int rec(int i, int j, vector<int> A, vector<int> B) {
            //base case
            if(i >= A.size() || j >= B.size())
                return 0;
            
            // cache check
            if(dp[i][j] != -1)
                return dp[i][j];

            // compute
            int ans = 0;
            ans = max(ans, rec(i + 1, j, A, B));
            ans = max(ans, rec(i, j + 1, A, B));
            if(A[i] == B[j]) {
                ans = max(ans, 1 + rec(i + 1, j + 1, A, B));
            }
            // save and return
            return dp[i][j] = ans;
        }
        int LCS(vector<int> A, vector<int> B) {
            dp.resize(A.size(), vector<int>(B.size(), -1));
            return rec(0, 0, A, B);
        }
};

int main (int argc, char *argv[]) {
    return 0;
}
