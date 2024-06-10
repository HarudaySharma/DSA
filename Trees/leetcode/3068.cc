#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges) {
            long long maxSum = 0;

            vector<int> delta;
            for (auto num : nums) {
                maxSum += num;
                delta.push_back((num ^ k) - (num));
            }
            // sort in reverse
            sort(delta.begin(), delta.end(), greater<int>());
            for (int i = 0; i < delta.size(); i += 2) {
                if (i >= delta.size() - 1)
                    break;
                int pathDelta = delta[i] + delta[i + 1];
                if (pathDelta <= 0)
                    break;
                maxSum += pathDelta;
            }
            return maxSum;
        }
};


