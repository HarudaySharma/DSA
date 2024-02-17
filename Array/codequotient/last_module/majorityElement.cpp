#include "bits/stdc++.h"
#include <map>
using namespace std;

int getMajorityElement(int arr[], int size) {
    map<int, int>freq;
    for(auto i = 0; i < size; i++) {
        if(freq.count(arr[i]))
            freq[arr[i]] += 1;
        else
            freq[arr[i]] = 1;
    }
    for(auto el : freq) {
        if(el.second > size / 2) 
            return el.first;
    }
    return -1;
}
