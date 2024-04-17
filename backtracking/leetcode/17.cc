#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:

        pair<int, int> getLetters(char digit) {
            // letters[i] = (A + (3 * (i - 2));
            int d = digit - '0';
            int i = 'a' + (3 * (d - 2));
            int j = 'a' + (3 * (d - 2)) + 2;
            switch (d) {
                case 7:
                    return {i, j + 1};
                case 8:
                    return {i + 1, j + 1};
                case 9:
                    return {i + 1, j + 2};
                default:
                    return {i, j};
            }
        }

    public:

        vector<string> res;
        void rec(string &digits, int i, string comb) {
            if(i == digits.size()) {
                res.push_back(comb);
                return;
            }
            pair<int, int> range = getLetters(digits[i]);
            for(int ch = range.first; ch <= range.second; ch++) {
                comb.push_back(ch);
                rec(digits, i + 1, comb);
                comb.pop_back();
            }
            return;
        }
        vector<string> letterCombinations(string digits) {
            if(digits.empty()) {
                return res;
            }
            rec(digits, 0, "");
            return res;
        }
};

