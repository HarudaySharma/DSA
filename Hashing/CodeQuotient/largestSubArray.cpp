#include "bits/stdc++.h"
#include <unordered_map>
using namespace std;

// approach: 
//  think if the sum of the sequence till a particular element is X and
//  it is true for other element also which is positioned after that previous element
//  that means the positional gap b/w these two elements made no effect on the sum of the sequence i.e. K 
//  therefore that gap can be considered as an subarray giving the sum 0
//  and we have to find all those subarrays and compare there length and output the largest length subarray

// implementation:
// store the sum of all the elements coming before an index and with each traveral of the array 
// find if that sum has occured before or not
// if yes then take the difference of the current position with the position where that sum was obtained. 
// and that would be the subarray length, compare such subarrays length and store the maximum length
int largSubArray(int *arr, int n) {
    unordered_map<int, int> map;
    long long sum = 0;
    int max_len = -1;
    int i;
    // way to solve the problem without checking for the sum == 0 explicitly and letting the hashmap handle it
    for(i = 0; i < n; i++) {
        auto it = map.find(sum);
        if(it != map.end()) {
            max_len = i - it->second > max_len ? i - it->second : max_len;
        } 
        else
            map.insert({sum, i});
        
        sum += arr[i];
    }
    auto it = map.find(sum);
    if(it != map.end()) {
        max_len = i - it->second > max_len ? i - it->second : max_len;
    } 
    return max_len;
    
}
int largSubArray2(int *arr, int n) {
    unordered_map<int, int> map;
    long long sum = 0;
    int max_len = -1;
    int i;
    // explicitly checking for the sum == 0 as if that the case then the subArray length would be from the start
    for(i = 0; i < n; i++) {
        sum += arr[i];
        if(sum == 0){
            max_len = max_len < i + 1 ? i + 1: max_len;
        }

        auto it = map.find(sum);
        if(it != map.end()) {
            max_len = i - it->second > max_len ? i - it->second : max_len;
        } 
        else
            map.insert({sum, i});
        
    }
    return max_len;
}


int main() {
    int arr[] = {11,2,-2,10,1,-4,-7,19};
    cout << largSubArray(arr, 8);
    return 0;
    
}
