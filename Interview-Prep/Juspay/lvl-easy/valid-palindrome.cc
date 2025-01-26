#include <bits/stdc++.h>

using namespace std;

// A phrase is a palindrome if, after converting all uppercase letters into
// lowercase letters and removing all non-alphanumeric characters, it reads the
// same forward and backward. Alphanumeric characters include letters and
// numbers.
//
// Given a string s, return true if it is a palindrome, or false otherwise.
//
//
//
// Example 1:
//
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while(i < j) {
            while(i < s.size() && !isalnum(s[i])) {
                i++;
            }
            while(j > 0 && !isalnum(s[j])) {
                j--;
            }

            if(i >= s.size() || j < 0) {
                break;
            }
            if(tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++, j--;
        }

        return true;
    }
};
