#include <bits/stdc++.h>

using namespace std;

//
// Given a string s, find the longest palindromic subsequence's length in s.
//
// A subsequence is a sequence that can be derived from another sequence by
// deleting some or no elements without changing the order of the remaining
// elements.
//
//
//
// Example 1:
//
// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
//
// Example 2:
//
// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".
//
//
//
// Constraints:
//
//     1 <= s.length <= 1000
//     s consists only of lowercase English letters.
//
//

class Solution {
private:
    vector<vector<int>>dp;

public:
    int longestPalindromeSubseq(string s) {
        string revS = s;
        reverse(begin(revS), end(revS));

        dp.resize(s.length(), vector<int>(s.length(), -1));

        return longestCommonSubSeq(0, 0, s, revS);
    }


private:
    int longestCommonSubSeq(int i, int j, string &s1, string &s2) {
        if(i >= s1.size() || j >= s2.size()) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // only 3 possibilites for subsequences
        int maxLen = longestCommonSubSeq(i, j + 1, s1, s2);
        maxLen = max(maxLen, longestCommonSubSeq(i + 1, j, s1, s2));

        if(s1[i] == s2[j]) {
            maxLen = max(maxLen, 1 + longestCommonSubSeq(i + 1, j + 1, s1, s2));
        }

        return dp[i][j] = maxLen;
    }
};


