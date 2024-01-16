#include "bits/stdc++.h"
#include <vector>
using namespace std;

int kthDistinctElement(vector<int> arr, int n, int k) {
    int max = arr[0];
    for(auto el : arr) {
        if(max < el) max = el;
    }
    int *hash = new int[max + 1];
    for(auto el : arr) {
        hash[el] = 0;
    }
    for (auto el : arr) {
        hash[el] += 1;
    }
    for (auto el : arr) {
        if(hash[el] == 1) {
            k--;
            if(k == 0) {
                return el;
            }
        }
    }
    return 0;
}

int main (int argc, char *argv[]) {
    
    return 0;
}

