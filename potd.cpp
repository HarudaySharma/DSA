#include <bits/stdc++.h>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <queue>
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

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        /* Approach
         * how to get the rank of max number 
         * => it will be the count of distinct eles in the arr.
         * how to get the rank of other eles?
         * create a map b/w element and its rank
         *  how ? Using HashMap & Priority Queue?
         *   why? PQ for mapping the rank with corresponding eles.
         *        and HashMap to store (ele, rank)
         *   the size of pq will be the rank of maxEle.
         */
        map<int, int> mp;
        priority_queue<int> pq;
        for(int el : arr) {
            if(!mp.count(el)) {
                pq.push(el);
                mp[el] = 1;
            }
        }

        int rank = pq.size();
        while(!pq.empty()) {
            mp[pq.top()] = rank--;
            pq.pop();
        }

        vector<int> rankArr;
        for(auto el : arr) {
            rankArr.push_back(mp[el]);
        }

        return rankArr;
    }
};

