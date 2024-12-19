#include <bits/stdc++.h>
#include <cctype>
#include <sstream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        stringstream cleanStrB;
        for(auto ch : s) {
            ch = tolower(ch);
            if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
                cleanStrB << ch;
            }
        }

        string cleanStr = cleanStrB.str();
        int i = 0, j = cleanStr.length() - 1;
        while(i < j) {
            if(cleanStr[i] != cleanStr[j])
                return false;
            i++; j--;
        }

        return true;
    }
};

