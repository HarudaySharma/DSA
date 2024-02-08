#include "bits/stdc++.h"
#include <utility>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i, j;
        for(i = 0, j = s.size() - 1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};
