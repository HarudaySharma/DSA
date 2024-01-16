#include "bits/stdc++.h"
using namespace std;

int maxFrequency(int arr[], int n) {
    int freq[1001] {0};
    for(int i = 0; i < n; i++){
        freq[arr[i]] += 1;
    }

    int res[2] = {arr[0], freq[arr[0]]};
    for(int i = 1; i < n; i++) {
        if(res[1] < freq[arr[i]]) {
            res[0] = arr[i];
            res[1] = freq[arr[i]];
        }
        else if(res[1] == freq[arr[i]] && res[0] > arr[i]) {
            res[0] = arr[i];
        }
    }

    return res[0];
}

int main (int argc, char *argv[]) {
    
    return 0;
}
