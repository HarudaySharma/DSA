#include<bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto el : stones) {
            pq.push(el);
        }
        while(pq.size() >= 2) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            x -= y;
            if(x != 0)
                pq.push(x);
        }
        return pq.empty() ? 0 : pq.top();
    }
};

