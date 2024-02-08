#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>

int isDivisibleInPairs(int *arr, int n, int k) {
    std::unordered_multiset<int> hash;
    for(int i = 0; i < n; i++) {
        int key = k - (arr[i] % k);
        auto it = key == k ? hash.find(0) : hash.find(key);
        if(it != hash.end()) {
            hash.erase(it);
            i++;
        }
        else {
            hash.insert(arr[i] % k);
        }
    }
    return hash.size() == 0 ? 1 : 0;
    
}

int main (int argc, char *argv[]) {
    
    return 0;
}
