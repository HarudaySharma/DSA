#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        // if both have even number of elements => (xor of same number is 0)
        if(n1 % 2 == 0 && n2 % 2 == 0) {
            return 0;
        }

        // take xor of all the elements of an array whose no. of elements are even
        // iff other array no. of elements are odd
        if(n1 % 2 == 0 && n2 % 2 != 0) {
            for(auto el : nums1) {
                res ^= el;
            }
        } else if(n2 % 2 == 0 && n1 % 2 != 0) {
            for(auto el : nums2) {
                res ^= el;
            }
        } else  { // both arrays has odd count of elements then take xor of all the elements in both the arrays.
            for(auto el : nums1) {
                res ^= el;
            }
            for(auto el : nums2) {
                res ^= el;
            }
        }

        return res;
    }
};

