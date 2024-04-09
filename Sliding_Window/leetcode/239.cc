#include <bits/stdc++.h>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;// will store the indices
        vector<int> windows;
        int l = 0;
        for(int r = 0; r < nums.size(); r++) {
            while(!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }
            q.push_back(r);
            // popping from the queue if left is ahead of queue front() => index
            if(l > q.front()){
                q.pop_front();
            }
            if(r + 1  >= k) {
                windows.push_back(nums[q.front()]);
                l++;
            }
        }
        return windows;
    }
};
