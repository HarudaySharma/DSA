#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {

        auto approach1 = [&]() -> int {
            int flips = 0;
            while(c) {
                if(c & 1) {
                    // if | is not 1 -> need to make any bit 1 for | to be 1
                    flips += ((a & 1) | (b & 1)) ? 0 : 1;
                }
                else {
                    // to make | 0 => both bit of a and b must be 0
                    if(a & 1)
                        flips += 1;
                    if(b & 1)
                        flips += 1;
                }
                a >>= 1;
                b >>= 1;
                c >>= 1;
            }

            // make the rest of the bits left in a && b => 0
            while(a) {
                if(a & 1)
                    flips += 1;
                a >>= 1;
            }

            while(b) {
                if(b & 1)
                    flips += 1;
                b >>= 1;
            }

            return flips;
        };

        auto approach2 = [&]() -> int {
            // we want (a|b) == c
            // xor of (a | b) and c will make every non bit pair 1
            // thus, the set bits it will contain will be the minFlips required
            int x = (a | b) ^ c;  
            int bothBit1 = x & (a & b); // flips required there are 2 
            int minFlips = 0;

            while(x) {
                if(x & 1)
                    minFlips += 1;
                x >>= 1;
            }
            while(bothBit1) {
                if(bothBit1 & 1)
                    minFlips += 1;
                bothBit1 >>= 1;
            }
            
            return minFlips;
        };

        return approach2();
    }
};



