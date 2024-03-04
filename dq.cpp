#include <bits/stdc++.h>
#include <set>
#include <utility>
using namespace std;

class Solution {
public:
    bool increaseScore(multiset<int> &tokens, int &power) {
        if(*tokens.begin() > power)
            return false;
        power -= *tokens.begin();
        tokens.erase(tokens.begin());
        return true;
    }

    int bagOfTokensScore(vector<int>& tokens, int power) {
        multiset<int>st(tokens.begin(), tokens.end());
        int score = 0;
        while(!st.empty()) {
            if(!increaseScore(st, power)) {
                if(st.size() <= 1 || score == 0) {
                    return score;
                }
                score -= 1;
                power += *st.rbegin();
                st.erase(--st.end());
            }
            else {
                score += 1;
            }

        }
        return score;
    }
};
