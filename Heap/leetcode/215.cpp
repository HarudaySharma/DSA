#include "bits/stdc++.h"
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto el : nums) {
            pq.push(el);
        }
        while(--k) {
            pq.pop();
        }
        return pq.top();
    }
};
