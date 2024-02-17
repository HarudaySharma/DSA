#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for(auto el1 : arr1) {
            int i = 0;
            for(i = 0; i < arr2.size(); i++) {
                if(abs(el1 - arr2[i]) <= d) {
                    break;
                }
            }
            if(i == arr2.size())
                count++;
        }
        return count;
    }
};
