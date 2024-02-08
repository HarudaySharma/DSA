#include <set>
bool pairSum(int arr[], int n, int k) {  
    std::set<int>hash;
    for(int i = 0; i < n; i++) {
        if(hash.find(k - arr[i]) != hash.end())
            return true;
        hash.insert(arr[i]);
    }
    return false;
}
