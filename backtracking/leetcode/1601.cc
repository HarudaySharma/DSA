#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>> &requests) {

        auto rec = [&](int idx, vector<int> &buildings, auto &&rec) -> int {
            if (idx >= requests.size()) {
                for (auto building : buildings) {
                    if (building != 0) {
                        return -1;
                    }
                    return 0;
                }
            }

            // don't consider the current request
            int maxReq = -1;
            int count1 = rec(idx + 1, buildings, rec);
            if(count1 != -1) {
                maxReq = count1;
            }

            int fromIdx = requests[idx][0];
            int toIdx = requests[idx][1];

            // consider the current request
            buildings[fromIdx] -= 1;
            buildings[toIdx] += 1;

            int count2 = rec(idx + 1, buildings, rec);
            if(count2 != -1) {
                maxReq = max(maxReq, count2 + 1);
            }

            buildings[fromIdx] += 1;
            buildings[toIdx] -= 1;

            return maxReq;
        };

        vector<int> buildings(n, 0);
        return rec(0, buildings, rec);
    }
};
