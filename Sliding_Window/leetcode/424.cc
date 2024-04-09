#include <algorithm>
#include <bits/stdc++.h>
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
    int approach2(string s, int k) {
        int freq[26]{0};
        int maxFreq = 0;
        int maxSubLen = 0;
        for(int l = 0, r = 0; r < s.size(); r++) {
            char ch = s[r];
            freq[ch - 'A'] += 1;
            maxFreq = max(maxFreq, freq[ch - 'A']);
            // checking the number of replacements
            // we have to do in present window
            while((r - l + 1) - maxFreq > k) {
                char chLeft = s[l];
                freq[chLeft - 'A'] -= 1;
                l++;
            }
            maxSubLen = max(r - l + 1, maxSubLen);
        }
        return maxSubLen;
    }
};
