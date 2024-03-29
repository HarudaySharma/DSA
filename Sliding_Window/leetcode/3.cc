#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        map<int, int>count;
        for(int left = 0, right = 0; right < s.size(); right++) {
            count[s[right]] += 1;
            while(count[s[right]] > 1){
                count[s[left++]] -= 1;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
