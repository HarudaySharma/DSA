#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int minUnfairness = INT_MAX;
        vector<int> childCookies(k);

        auto rec = [&](int i, auto &&rec) {
            if(i >= cookies.size()) {
                auto currUnfairness = max_element(begin(childCookies), end(childCookies));
                minUnfairness = min(minUnfairness, *currUnfairness);
                return;
            }

            for(auto &child : childCookies) {
                child += cookies[i];
                rec(i + 1, rec);
                child -= cookies[i];
            }

            return;
        };

        rec(0, rec);

        return minUnfairness;
    }
};


