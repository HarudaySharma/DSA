#include <vector>
using namespace std;

class Solution {
    public:
        int numTilings(int n) {
            int MOD = 1e9 + 7;
            vector<int> dp(1001, -1);

            auto rec = [&](int n, auto &&rec) -> int {
                if (n == 1 || n == 2)
                    return n;
                if (n == 3)
                    return 5;
                if (dp[n] != -1)
                    return dp[n];

                return dp[n] = ((2 * rec(n - 1, rec) % MOD) + (rec(n - 3, rec) % MOD)) % MOD;
            };

            return rec(n, rec);
        }
};
