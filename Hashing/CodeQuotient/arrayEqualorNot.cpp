#include "bits/stdc++.h"
#include <vector>
using namespace std;

int arraysEqualorNot(vector<int> v1, vector<int> v2) {
    if(v1.size() != v2.size()) return 0;

    int max1 = INT_MIN;
    int max2 = INT_MIN;
    for(auto it1 = v1.begin(), it2 = v2.begin(); it1 != v1.end() && it2 != v2.end(); it1++, it2++){
        if(*it1 > max1) max1 = *it1;
        if(*it2 > max2) max2 = *it2;
    }
    if(max1 != max2) return 0;

    int* hash = new int[abs(max1) + 1];
    for(auto it1 = v1.begin(), it2 = v2.begin(); it1 != v1.end() && it2 != v2.end(); it1++, it2++){
        hash[abs(*it1)] = 0;
        hash[abs(*it2)] = 0;
    }
    for(auto el : v1) {
        hash[abs(el)] += 1;
    }
    for (auto el : v2) {
        if(hash[abs(el)] == 0) {
            delete [] hash;
            return 0; 
        }
        hash[abs(el)] -= 1;
    }
    delete [] hash;
    return 1;
}

int main (int argc, char *argv[]) {
    
    return 0;
}
