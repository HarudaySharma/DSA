#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    public:
        int printSubsets(int i, vector<int> &nums, vector<int> subsets, int left, vector<vector<int>> &cache) {
            if(left < 0)
                return 0;
            if(left == 0) {
                cout << "{ ";
                for(auto num : subsets)
                    cout << num << " ";
                cout << "}" << endl;
                return 1;
            }
            if(cache[i][left] != -1) {
            }
            int notake = printSubsets(i + 1, nums, subsets, left, cache);
            subsets.push_back(nums[i]);
            int take = printSubsets(i + 1, nums, subsets, left - nums[i], cache);
            return cache[i][left] = notake || take;
        }

        // find number of subsets with sum = k
        int numberOfSubsets(int i, int sum, int target, vector<int> &arr, int &n, vector<vector<int>> &cache) {
            // pruning
            //base case
            if(i == n)
                return 0;
            if(sum == target)
                return 1;
            //cache check
            if(cache[i][sum] != -1) {
                return cache[i][sum];
            }
            // transition
            cache[i][sum] = numberOfSubsets(i + 1, sum, target, arr, n, cache) 
                + numberOfSubsets(i + 1, sum + arr[i], target, arr, n, cache);
            return cache[i][sum];
        }
        int targetSum(vector<int> &arr, int target) {
            int n = arr.size();
            vector<vector<int>> cache(n, vector<int>(1e4 + 1, -1));
            return numberOfSubsets(0, 0, target, arr, n, cache);
        }

};
int main (int argc, char *argv[]) {
    vector<int> arr{12, 1, 61, 5, 9, 2};
    int k = 24;
    Solution s;
    cout << s.targetSum(arr, k) << endl;
    return 0;
}

