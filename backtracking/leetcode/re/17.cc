#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> getRange(char dig) {
        int d = dig - '0';
        int lb = 'a' + (d - 2) * 3;
        int ub = lb + 2;

        switch (dig) {
            case '7': return {lb, ub + 1};
            case '8': return {lb + 1, ub + 1};
            case '9': return {lb + 1, ub + 2};
            default: return {lb, ub};
        };
    }

    vector<string> letterCombinations(string digits) {
        vector<string> letters;

        for(auto dig : digits) {
            auto range = getRange(dig);
            string tmp;
            while(range.first <= range.second) {
                tmp.push_back(range.first);
                range.first += 1;
            }
            letters.push_back(tmp);
        }

        // compute all the combinations of the letters.
        vector<string> combinations;

        auto rec = [&](int idx, string res, auto &&rec) -> void {
            if(idx == letters.size()) {
                if(res.empty())
                    return;
                combinations.push_back(res);
                return;
            }

            for(auto dig : letters[idx]) {
                res.push_back(dig);
                rec(idx + 1, res, rec);
                res.pop_back();
            }
            return;
        };
        rec(0, "", rec);

        return combinations;
    }
};
