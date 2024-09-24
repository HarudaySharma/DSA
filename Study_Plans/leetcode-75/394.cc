#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <stack>
#include <string>
using namespace std;
//
// Example 1:
//
// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
//
// Example 2:
//
// Example 3:
//
// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"

// SOLUTION:
// use stack to store all the characters
// should store the numbers differently?
//  NO -> because there can be a nested situation
//  save the numbers in stack itself
class Solution {
    bool isNumber(char ch) { return ch >= '0' && ch <= '9'; }

    public:
    string decodeString(string s) {

        stack<char> st;
        int i = 0;
        while (i < s.length()) {
            if(s[i] == ']') {
                // get the string
                string str;
                while(st.top() != '[') {
                    str.push_back(st.top());
                    st.pop();
                } 
                st.pop();
                reverse(str.begin(), str.end());

                int num = 0;
                int mul = 1;
                while(!st.empty() && isNumber(st.top())) {
                    int dig = st.top() - '0';
                    num += (dig * mul);
                    mul *= 10;
                    st.pop();
                }
                while(num--) {
                    for(auto ch : str)
                        st.push(ch);
                }
            }
            else
                st.push(s[i]);
            i++;
        }

        string res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
