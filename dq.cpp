#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &str) {
        for(int i = 0, j = str.length() - 1; i < j; i++, j--){
            if(str.at(i) != str.at(j))
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto str : words) {
            if(isPalindrome(str))
                return str;
        }
        return "";
    }
};
