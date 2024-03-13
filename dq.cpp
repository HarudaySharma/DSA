#include <bits/stdc++.h>
#include <map>
#include <type_traits>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        if(n <= 1)
           return -1;
        int sum = n * (n + 1) / 2;
        int i = 1;
        int s = 0;
        while(i < n) {
            s += i;
            if(sum - s == s - i)
                return i;
            i++;
        }
        return -1;
    }
};
