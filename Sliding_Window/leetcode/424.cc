#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class Solution {
public:
    pair<char, int> maxFreq(map<char, int> &freq) {
        pair<char, int> maxPair{'A', -1};
        for(auto pr : freq){
            if(maxPair.second < pr.second)
                maxPair = pr;
        }
        return maxPair;
    }

    int characterReplacement(string s, int k) {
        int maxLen = 0;
        // at max (26 key:value pairs will be stored)
        map<char, int> freq;
        for(int left = 0, right = 0; right < s.size(); right++) {//O(26 * N)
            //incrementing the char fre count
            freq[s[right]] += 1;
            // getting the most frequent char in window
            pair<char, int>maxPair = maxFreq(freq);
            // checking if the window is valid(substitutions <= k ?)
            while((right - left + 1) - (maxPair.second) > k){
                freq[s[left++]] -= 1;
                maxPair = maxFreq(freq);
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
