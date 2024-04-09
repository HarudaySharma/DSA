#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stringIsSame(map<char, int> &hash_s1, map<char, int> &hash_s2){
        for(auto pr : hash_s2) {
            if(pr.second == 0)
                continue;;
            auto it1 = hash_s1.find(pr.first);
            if(it1 == hash_s1.end() || it1->second != pr.second){
                return false;
            }
        }
        for(auto pr : hash_s1) {
            auto it2 = hash_s2.find(pr.first);
            if(it2 == hash_s2.end() || it2->second != pr.second){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        map<char, int> hash_s1;
        for(auto ch : s1)
            hash_s1[ch] += 1;
        
        map<char, int> hash_s2;
        for(int left = 0, right = 0; right < s2.size(); right++) {
            hash_s2[s2[right]] += 1;
            if(right - left + 1 == s1.size()) {
                if(stringIsSame(hash_s1, hash_s2))
                    return true;
                else
                 hash_s2[s2[left++]] -= 1;
            }
        }
        return false;
    }

};

/* // need some minor fixes
class Solution2 {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> hash_s1;
        map<char, int> hash_s2;
        // initializing all letters count = 0
        for(char ch = 'a'; ch <= 'z'; ch++) {
            hash_s1[ch] = 0;
            hash_s2[ch] = 0;
        }
        for(auto ch : s1) hash_s1[ch] += 1;
        // checking every substr in s2 with len(s1)
        int sameCount = 0;
        int right = 0;
        while(right < s1.size()){
            char ch = s2[right++];
            hash_s2[ch] += 1;
            if(hash_s2[ch] == hash_s1[ch])
                sameCount += 1;
        }
        if(sameCount == 26)
            return true;

        for(int left = 0; right < s2.size(); right++) {
            char leftChar = s2[left];
            char rightChar = s2[right];

            hash_s2[rightChar] += 1;
            if(hash_s2[rightChar] == hash_s1[rightChar])
                sameCount += 1;

            hash_s2[leftChar] -= 1;
            if(hash_s2[leftChar] == hash_s1[leftChar])
                sameCount -= 1;
            if(sameCount == 26)
                return true;
        }
        return sameCount == 26;
    }
}; */
