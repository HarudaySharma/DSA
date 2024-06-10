#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> dp;
    int climbStairs(int n) {
        if(n < 0){
            return 0;
        }
        if(n == 0)
            return 1;
        if(dp.count(n)) {
            return dp[n];
        }
        int noOfWays = climbStairs(n - 1);
        noOfWays += climbStairs(n - 2);
        dp[n] = noOfWays;
        return noOfWays;
    }
};

