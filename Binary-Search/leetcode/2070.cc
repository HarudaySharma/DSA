#include <algorithm>
#include <bits/stdc++.h>
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

class Comp {
public:
    bool operator() (const vector<int> &a, const vector<int> &b) const {
        return a[0] < b[0];
    }
};

class Solution {
public:

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        return usingBS(items, queries);
    }

    vector<int> bySortingQueries(vector<vector<int>>& items, vector<int>& queries) {
        map<int, vector<int>> qIdx;
        set<int> queriesSet;
        vector<int> res(queries.size(), 0);

        for(int i = 0; i < queries.size(); i++) {
            queriesSet.insert(queries[i]);
            qIdx[queries[i]].push_back(i);
        }

        sort(items.begin(), items.end(), Comp());

        int maxi = 0;
        int i = 0;
        for(auto query : queriesSet) {
            if(items[0][0] > query) {
                continue;
            }
            while(i < items.size() && items[i][0] <= query){
                maxi = max(maxi, items[i][1]);;
                i++;
            }
            while(!qIdx[query].empty()) {
                res[qIdx[query].back()] = maxi;
                qIdx[query].pop_back();
            }

        }

        return res;
    }

    vector<int> usingBS(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), Comp());
        vector<int> res(queries.size(), 0);

        int maxBeauty = 0;
        for(auto &item : items) {
            maxBeauty = max(maxBeauty, item[1]);
            item[1] = maxBeauty;// why ? items with less price can also have more beauty
        }
        for(int i = 0; i < queries.size(); i++) {
            res[i] = bs(queries[i], items);
        }


        return res;
    }

    int bs(int query, vector<vector<int>> &items) {
        int maxBeauty = 0;
        int l = 0;
        int r = items.size() - 1;

        while(l <= r) {
            int m = l + (r - l) / 2;
            if(items[m][0] > query) {
                // price > queryPrice
                r = m - 1;
            }
            else {
                maxBeauty = max(maxBeauty, items[m][1]);
                // price <= queryPrice
                l = m + 1;// moving right??? // why ? items with less price can also have more beauty. -> handled on line 76;
            }
        }

        return maxBeauty;
    }
};

