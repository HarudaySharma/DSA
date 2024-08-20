#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
    long val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(long x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(long x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

struct ListNode {
    long val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(long x) : val(x), next(nullptr) {}
    ListNode(long x, ListNode *next) : val(x), next(next) {}
};

/*
   You have a long flowerbed in which some of the plots are planted, and some are
   not. However, flowers cannot be planted in adjacent plots.

   Given an integer array flowerbed containing 0's and 1's, where 0 means empty and
   1 means not empty, and an integer n, return true if n new flowers can be planted
   in the flowerbed without violating the no-adjacent-flowers rule and false
   otherwise.



    Example 1:

        Input: flowerbed = [1,0,0,0,1], n = 1
        Output: true
        
    Example 2:

        Input: flowerbed = [1,0,0,0,1], n = 2
        Output: false
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> zeroPos;
        vector<int> res(nums.size(), 0);
        int prd = 1;

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(num == 0) {
                zeroPos.push_back(i);
                continue;
            }
            prd *= num;
        }

        if(zeroPos.size() > 1)
            return res;

        if(zeroPos.size()) {
            res[zeroPos.front()] = prd;
            return res;
        }

        for(int i = 0; i < nums.size(); i++) {
            res[i] = prd / nums[i];
        }

        return res;
    }
};

