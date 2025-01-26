#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = nums1.size() - nums2.size();
        int n2 = nums2.size();
        vector<int> merged(n1 + n2);

        int i1 = 0;
        int i2 = 0;
        int k = 0;
        while(i1 < n1 && i2 < n2) {
            if(nums1[i1] < nums2[i2]) {
                merged[k++] = nums1[i1++];
            } else {
                merged[k++] = nums2[i2++];
            }
        }

        while(i1 < n1) {
                merged[k++] = nums1[i1++];
        }
        while(i2 < n2) {
                merged[k++] = nums2[i2++];
        }

        nums1 = merged;

        return;
    }
};

