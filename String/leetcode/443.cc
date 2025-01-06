#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compress(vector<char> &chars) {
        for (auto curr = chars.begin(); curr != chars.end(); curr++) {
            int count = 1;

            for (auto j = curr + 1; j != chars.end();) {
                if (*j == *curr) {
                    j = chars.erase(j);
                    count += 1;
                } else {
                    break;
                }
            }
            if (count == 1) {
                continue;
            }

            string countStr = to_string(count);
            for (auto dig : countStr) {
                curr = chars.insert(curr + 1, dig);
            }
        }

        return chars.size();
    }
};
