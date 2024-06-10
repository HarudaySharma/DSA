#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        int count = 0;

        auto expand_from_middle = [&](int start, int end) {
            while(start >= 0 && end < len) {
                if(s[start--] != s[end++]) {
                    return;
                }
                count++;
            }
            return;
        };

        for(int i = 0; i < s.length(); i++) {
            expand_from_middle(i, i);
            expand_from_middle(i, i + 1);
        }
        return count;
    }
};

