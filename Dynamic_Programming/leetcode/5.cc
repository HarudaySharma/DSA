#include <bits/stdc++.h>
#include <string>
using namespace std;
 
class Solution {
public:

    string  getPalindrome(int i, int j, string &s) {
        while(j < s.length() && i >= 0 && s[i] == s[j]) {
            i--, j++;
        }
        return  s.substr(i + 1, j - i - 1);
    }

    string longestPalindrome(string s) {
        if(s.length() <= 1)
            return s;
        string res = "";
        for(int i = 0; i < s.length(); i++) {
            // for odd len palindrome
            auto odd = getPalindrome(i, i, s);
            // for even len palindrome
            auto even = getPalindrome(i, i + 1, s);
            // compare the larger len string with the so far longest string saved
            string &larger = odd.length() < even.length() ? even : odd;
            if(res.length() < larger.length()) {
                res = larger;
            }
        }
        return res;
    }
};

    /* DP (NOT WORKING)
     * map<pair<int, string>, string> dp;
    
    bool isPalindromic(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }

    // bb
    string rec(int i, string &s, int len, string subStr) {
        if(i >= len) {
            return "";
        }

        if(dp.count({i, subStr})) {
            return dp[{i, subStr}];
        }

        // check if the current subStr is palindromic
        string res = "";
        if(isPalindromic(subStr)) {
            res = subStr;// "", "b"
        }

        string one = rec(i + 1, s, len, subStr + s[i]);// b,  bb,
        string two = rec(i + 1, s, len, "");// 
        string three = rec(i + 1, s, len, to_string(s[i]));// 

        string potentialAns = one.length() < two.length() ? 
            one.length() < three.length() ? one : three :
            two.length() < three.length() ? two : three;
        
        if(res.empty()) {
            res = potentialAns;
        } else {
            if(!potentialAns.empty()) {
                res = res.length() < potentialAns.length() ? one : res;
            }
        }
        return dp[{i, subStr}] = res;
    } */
