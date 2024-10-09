#include<bits/stdc++.h>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        int i = 0;
        int j = costs.size() - 1;
        int limit = candidates;

        while(pq1.size() < candidates && i <= j) {
            pq1.push(costs[i++]);
        }

        while(pq2.size() < candidates && i <= j) {
            pq2.push(costs[j--]);
        }

        long long res = 0;
        while(k--) {
            int x = pq1.empty() ? INT_MAX : pq1.top();
            int y = pq2.empty() ? INT_MAX : pq2.top();

            if(x <= y) {
                res += x;
                pq1.pop();
                if(i <= j)
                    pq1.push(costs[i++]);
            }
            else {
                res += y;
                pq2.pop();
                if(i <= j)
                    pq2.push(costs[j--]);
            }
        }

        return res;
    }
};

