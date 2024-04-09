#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isVowel(char ch) {
            switch (ch) {
                case 'a': 
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    return true;
                    break;
            }
            return false;
        }
        int maxVowels(string s, int k) {
            int l = 0, r = 0;
            int maxVowels = 0;
            int vowels = 0;
            while(r < s.size()) {
                if(isVowel(s[r]))
                    vowels += 1;
                if(r - l + 1 == k) {
                    maxVowels = max(maxVowels, vowels);
                    if(isVowel(s[l++])) {
                        vowels -= 1;
                    }
                }
                r++;
            }
            return maxVowels;
        }
};
