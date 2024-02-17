#include "bits/stdc++.h"
#include <unordered_set>
using namespace std;

bool pairSum(int arr[], int n, int k) {
    unordered_set<int> hash;
    for(int i = 0; i < n; i++) {
        int target = k - arr[i];
        if(hash.count(target)) {
            return true;
        }
        hash.insert(arr[i]);
    }
    return false;
}

