#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        //return method1(word1, word2);
        return method2(word1, word2);
    }

    bool method2(string word1, string word2) {
        int freq1[26]{0};
        int freq2[26]{0};
        for(auto ch : word1) {
            freq1[ch - 'a'] += 1;
        }

        for(auto ch : word2) {
            freq2[ch - 'a'] += 1;
        }

        for(int i = 0; i < 26; i++) {
            if((freq1[i] == 0 && freq2[i] != 0) || (freq2[i] == 0 && freq1[i] != 0))
                return false;
        }

        // check if the occuerences of words in 1 string are same as that to other string characters.
        // it doesn't matter whether the same char should have the same frequency
        sort(freq1, freq1 + 26);
        sort(freq2, freq2 + 26);

        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i])
                return false;
        }

        return true;
    }

    bool method1(string word1, string word2) {
        map<char, int> mp1;
        for(auto ch : word1) {
            mp1[ch] += 1;
        }

        map<int, int> mp2;
        for(auto ch : word2) {
            mp2[ch] += 1;
        }

        for(auto &pr : mp2) {
            if(!mp1.count(pr.first) || mp1[pr.first] != pr.second)
                return false;
        }

        return true;
    }
};

