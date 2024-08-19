#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    long val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(long x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(long x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

struct ListNode {
    long val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(long x) : val(x), next(nullptr) {}
    ListNode(long x, ListNode *next) : val(x), next(next) {}
};

/*
   There is only one character 'A' on the screen of a notepad. You can perform one
   of two operations on this notepad for each step:

   Copy All: You can copy all the characters present on the screen (a partial
   copy is not allowed). Paste: You can paste the characters which are copied last
   time.

   Given an integer n, return the minimum number of operations to get the character
   'A' exactly n times on the screen.



    Example 1:

        Input: n = 3
        Output: 3
        Explanation: Initially, we have one character 'A'.
        In step 1, we use Copy All operation.
        In step 2, we use Paste operation to get 'AA'.
        In step 3, we use Paste operation to get 'AAA'.

    Example 2:

        Input: n = 1
        Output: 0

*/

class Solution {
    public:
        int minSteps(int n) {
            if(n == 1)
                return 0;

            // paste curr seq;
            // paste previous seq.
            // dp
            vector<int> dp(1001, -1);

            auto rec = [&](int curr, int paste, auto &&rec) -> int {
                if(curr > n)
                    return 1e9;
                if(curr == n)
                    return 0;
                if(dp[curr] != -1)
                    return dp[curr];

                // paste
                int x = rec(curr + paste, paste, rec) + 1;
                // copy & paste
                int y = rec(curr * 2, curr, rec) + 2;

                return dp[curr] = min(x, y);
            };

            return rec(1, 1, rec) + 1;
        }
};

