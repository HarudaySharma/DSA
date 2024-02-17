#include "bits/stdc++.h"
#include <pthread.h>
using namespace std;

/*     
 * Complete the 'specialIndex' function below.
 * @params
 *   arr -> An vector of integers
 *
 *  @return
 *    The index of an array such that the sum of elements at 
 *    lower indices is equal to the sum of elements at higher indices.
 */

int specialIndex(vector<int> arr) {
    map<int, long long> left;
    map<int, long long> right;
    long long lSum = 0;
    long long rSum = 0;
    for(int i = 0, j = arr.size() - 1; i < arr.size(); i++, j--) {
        left[i] = lSum;
        right[j] = rSum;
        lSum += arr[i];
        rSum += arr[j];
    }
    for(int i = 0; i < arr.size(); i++) {
        if(left[i] == right[i])
            return i;
    }
    return -1;
}
