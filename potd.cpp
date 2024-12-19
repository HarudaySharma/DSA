#include <bits/stdc++.h>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <utility>
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
    int minAddToMakeValid(string s) {
        int openCount = 0;
        int add = 0;

        for(auto ch : s) {
            if(ch == '(')
                openCount += 1;
            else {
                if(!openCount) {
                    add += 1;
                }
                else {
                    openCount -= 1;
                }
            }
        }

        return add + openCount;
    }
};

