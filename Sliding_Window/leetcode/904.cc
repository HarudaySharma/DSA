#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size() <= 1)
            return 1;
        int maxCount = 0;
        int l = 0, r = 1;
        pair<int, int> frt1{fruits[0], 1};
        pair<int, int> frt2{-1, 0};
        while(r < fruits.size()) {
            int currFrt = fruits[r];
            if(frt1.first == currFrt)
                frt1.second += 1;
            else if(frt2.first == -1 || frt2.first == currFrt) {
                frt2.first = currFrt;
                frt2.second += 1;
            }
            else {
                maxCount = max(maxCount, frt1.second + frt2.second);
                while(frt1.second != 0 && frt2.second != 0) {
                    int lFrt = fruits[l++];
                    if(lFrt == frt1.first) frt1.second -= 1;
                    else if(lFrt == frt2.first) frt2.second -= 1;
                }
                if(frt1.second == 0)
                    frt1 = {currFrt, 1};
                else
                 frt2 = {currFrt, 1};
            }
            r++;
        }
        maxCount = max(maxCount, frt1.second + frt2.second);
        return maxCount;
    }
};
