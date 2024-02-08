#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            int hash['z' - 'a' + 1]{0};
            for(auto el : s1) {
                hash[el - 'a'] += 1;
            }
            for(auto el : s2) {
                hash[el - 'a'] += 1;
            }
            for(auto el : s3) {
                hash[el - 'a'] -= 1;
            }
            for(int i = 0; i < 26; i++) {
                if(hash[i] > 0)
                    return false;
            }
            return true;
        }
};
