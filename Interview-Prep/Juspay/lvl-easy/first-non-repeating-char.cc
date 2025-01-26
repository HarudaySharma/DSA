#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Given a string s, find the first non-repeating character in it and return
    // its index. If it does not exist, return -1.
    int firstUniqChar(string s) {
        int freqArr[256]{0};

        for(auto ch : s) {
            freqArr[ch] += 1;
        }

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if(freqArr[ch] == 1) {
                return i;
            }
        }

        return -1;
    }
};
