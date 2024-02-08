#include "bits/stdc++.h"
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squares;
        for (auto el : nums) {
            if(squares.empty()) {
                squares.push_back(el * el);
                continue;
            }
            auto it = squares.begin();
            int sqr = el * el;
            while(it != squares.end()) {
                if(*it >= sqr) {
                    squares.insert(it, sqr);
                    break;
                }
                it++;
            }
            if(it == squares.end()) {
                squares.push_back(sqr);
            }
        }
        return squares;

    }
};
