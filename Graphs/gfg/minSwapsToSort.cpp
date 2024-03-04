//{ Driver Code Starts
#include<bits/stdc++.h>
#include <queue>
#include <utility>
using namespace std;

// } Driver Code Ends

class Solution {
    void swap(pair<int, int> &a, pair<int, int> &b) {
        auto temp = a;
        a = b;
        b = temp;
        return;
    }

    public:
        int minSwaps(vector<int>&nums) {
            vector<pair<int, int>>sorted;
            for(int i = 0; i < nums.size(); i++) {
                sorted.push_back({nums[i], i});
            }

            sort(sorted.begin(), sorted.end());
            int swaps = 0;
            for(int i = 0; i < nums.size(); i++) {
                while(i != sorted[i].second) {
                    swap(sorted[i], sorted[sorted[i].second]);
                    swaps++;
                }
            }
            return swaps;
        }
};

//{ Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans <<"\n";
    }
    return 0;
}
// } Driver Code Ends
