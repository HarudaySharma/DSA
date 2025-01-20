#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        /* int startBit = 0;
        if(rec(0, startBit, startBit, derived)) {
            return true;
        }

        startBit = 1;
        return rec(0, startBit, startBit, derived); */

        // NON RECURSIVE
        int startBit = 0;
        int prevBit = startBit;
        for(int i = 0; i < derived.size() - 1; i++) {
            int xorBit = derived[i];

            if(xorBit == 0) {
                continue;
            } else {
                prevBit = !prevBit;
            }
        }

        if((startBit ^ prevBit) == derived.back())
            return true;

        startBit = 1;
        prevBit = startBit;
        for(int i = 0; i < derived.size() - 1; i++) {
            int xorBit = derived[i];

            if(xorBit == 0) {
                continue;
            } else {
                prevBit = !prevBit;
            }
        }

        return (startBit ^ prevBit) == derived.back();
    }

    bool rec(int idx, int &startBit, int prevBit, vector<int> &derived) {
        if(idx >= derived.size() - 1) {
            // check the first and last dig xor
            return (startBit ^ prevBit) == derived.back();
        }

        int xorVal = derived[idx];

        if(xorVal == 0) {
            return rec(idx + 1, startBit, prevBit, derived);
        } else {
            return rec(idx + 1, startBit, !prevBit, derived);
        }

    }

};



