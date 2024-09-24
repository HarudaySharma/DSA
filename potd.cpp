#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>
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
   Given a list of 24-hour clock time points in "HH:MM" format, return the minimum
   minutes difference between any two time-points in the list.



   Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1

Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0



Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM" */

class comp {
    public:
        bool operator()(const string t1, const string t2) const {
            int h1 = stoi(t1.substr(0, 2));
            int h2 = stoi(t2.substr(0, 2));
            int m1 = stoi(t1.substr(3, 2));
            int m2 = stoi(t2.substr(3, 2));

            return h1 > h2 || m1 > m2;
        }
};

class Solution {
public:
    int findKthNumber(int n, int k) {
        
        long long currNum = 1;
        int count = 1;
        while(count < k) {
            count += 1;

            if(currNum * 10 <= n)
                currNum *= 10;
            else {
                while(currNum == n || currNum % 10 == 9)
                    currNum /= 10;
                currNum += 1;
            }
        }

        return currNum;
    }
};

