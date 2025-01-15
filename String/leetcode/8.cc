#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        // " ", "+/-", "leading zeros",
        int i = 0;
        stringstream ss;

        while(i < s.length() && s[i] == ' ') i++;// ignoring whitespace

        char numSign = '+';
        if(s[i] == '-') {
            numSign = '-';
            i++;
        } else if(s[i] == '+') {
            numSign = '+';
            i++;
        }

        while(i < s.length() && s[i] == '0') i++; // skipping leading zeros
        while(i < s.length() && isNum(s[i])) {
            ss << s[i];
            i++;
        }

        if(ss.str().size() == 0)
            return 0;

        long long num = stringToNum(ss.str());
        num = numSign == '-' ? num * -1 : num;

        // < -2^(31)  => -2^(31)
        if(num < - pow(2, 31)) {
            num = -pow(2, 31);
        }
        // > 2^(31) - 1  => 2^31 - 1
        if(num > pow(2, 31) - 1) {
            num = pow(2, 31) - 1;
        }

        return (int) num;
    }

    long long stringToNum(string str) {
        long long num = 0;
        for(auto ch : str) {
            if(num > pow(2, 31))
                return num;
            num = num * 10 + (ch - '0');
        }

        return num;
    }

    bool isNum(char ch) {
        return ch >= '0' && ch <= '9';
    }
};
