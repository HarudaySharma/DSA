#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class comp {
    public:
        bool operator() (const pair<int, int> a, const pair<int, int> b) const {
            return a.first > b.first;
        }
};

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<pair<int, int>> nums;
        for(int i = 0; i < nums1.size(); i++) {
            nums.push_back({nums2[i], nums1[i]});
        }

        sort(nums.begin(), nums.end(), comp());
        priority_queue<int, vector<int>, greater<int>> pq;

        long long res = 0;
        long long sum = 0;
        int i = 0;
        while(i < nums.size()) {
            sum += nums[i].second;
            pq.push(nums[i].second);

            if(i >= k - 1) {
                res = max(res, (long long) sum * nums[i].first);
                sum -= pq.top();
                pq.pop();
            }

            i++;
        }

        return res;
    }
};

