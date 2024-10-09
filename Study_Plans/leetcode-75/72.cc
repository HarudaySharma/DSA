#include "bits/stdc++.h"
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
        int minDistance(string word1, string word2) {
            vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));

            auto rec = [&](int i, int j, auto &&rec) -> int {
                if(j >= word2.length()) 
                    return word1.length() - i;
                if(i >= word1.length()) {
                    return word2.length() - j;
                }
                if(word1[i] == word2[j]) {
                    return rec(i + 1, j + 1, rec);
                }

                if(dp[i][j] != -1)
                    return dp[i][j];

                int minD = INT_MAX;
                //remove
                minD = min( minD, 1 + rec(i + 1, j, rec));
                // insert
                minD = min( minD, 1 + rec(i, j + 1, rec));
                // replace.
                minD = min(minD, 1 + rec(i + 1, j + 1, rec));

                return dp[i][j] = minD;
            };

            return rec(0, 0, rec);
        }
};

int main() {
    Solution s;
    s.minDistance("horse", "ros");
}

