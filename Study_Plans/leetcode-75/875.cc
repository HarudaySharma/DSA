#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minEatingSpeed(vector<int> &piles, int h) {
            auto canEatAll = [&](int k) -> bool {
                int hours = 0;
                for(auto pile : piles) {
                    hours += pile / k;
                    if(pile % k != 0)
                        hours++;
                }

                return hours <= h;
            };

            int low = 1;
            int high = *max_element(piles.begin(), piles.end());

            while (low < high) {
                int mid = low + (high - low) / 2;
                if(canEatAll(mid)) {
                    high = mid;
                }
                else {
                    low = mid + 1;
                }
            }

            return high;
        }
};
