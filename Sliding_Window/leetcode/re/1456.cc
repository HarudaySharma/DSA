#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i'
            || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int l = 0;
        int r = 0;
        int maxVowels = 0;
        int vowels = 0;

        while(k--) {
            if(isVowel(s[r++]))
                vowels += 1;
            maxVowels = max(maxVowels, vowels);
        }

        while(r < s.length()) {
            if(isVowel(s[r++]))
                vowels += 1;
            if(isVowel(s[l++]))
                vowels -= 1;
            maxVowels = max(maxVowels, vowels);
        }

        return maxVowels;
    }
};

