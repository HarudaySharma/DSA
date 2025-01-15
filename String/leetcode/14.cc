#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string bruteForce(vector<string>& strs) {
        int x = 0;
        stringstream ss;

        while(true) {
            char ch = strs[0][x];
            for(auto str : strs) {
                if(x >= str.length()) {
                    return ss.str();
                }
                if(ch != str[x]) {
                    return ss.str();
                }
            }

            ss << ch;
            x++;
        }

        return ss.str();
    }


    string optimalSolution(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[strs.size() - 1];

        int i = 0;
        stringstream ss;
        while(true) {
            if(i > first.length() || i >= last.length()) {
                return ss.str();
            }
            if(first[i] != last[i]) {
                return ss.str();
            }

            ss << first[i];
            i++;
        }

        return "";
    }

    string longestCommonPrefix(vector<string>& strs) {
        return optimalSolution(strs);
    }
};

