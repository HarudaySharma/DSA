#include<bits/stdc++.h>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int freq[256]{0};
        for(auto ch : s) {
                freq[ch] += 1;
        }
        unordered_map<int, vector<char>>hash;
        for(int i = 0; i < 256; i++) {
            if(freq[i] != 0) {
                auto it = hash.find(freq[i]);
                if(it != hash.end()) {
                    it->second.push_back(i);
                }
                else {
                    vector<char> chars;
                    chars.push_back(i);
                    hash.insert({freq[i], chars});
                }
            }
        }
        int size = s.size();
        s.clear();
        for(int i = size; i >= 0; i--) {
            auto it = hash.find(i);
            if(it != hash.end()) {
                for(auto ch : it->second) {
                    for(int j = 1 ; j <= i; j++) 
                        s.push_back(ch);
                }
            }
        }
        return s;
    }
};
