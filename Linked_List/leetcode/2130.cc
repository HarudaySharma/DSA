#include <bits/stdc++.h>
using namespace std;

/* In a linked list of size n, where n is even, the ith node (0-indexed) of the
   linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2)
   - 1.

   For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the
   twin of node 2. These are the only nodes with twins for n = 4.

   The twin sum is defined as the sum of a node and its twin.

   Given the head of a linked list with even length, return the maximum twin sum
   of the linked list. */

struct ListNode {

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    private:
        int calSize(ListNode *head) {
            int size = 1;

            ListNode *slow = head;
            ListNode *fast = head;
            while(fast && fast->next) {
                size += 2;
                slow = slow->next;
                fast = fast->next->next;
            }

            return fast ? size + 1 : size;
        }

    public:
        int pairSum(ListNode *head) {
            // store the nums till the half of the list
            vector<int> nums;

            int half = calSize(head) / 2;
            while(half--) {
                nums.push_back(head->val);
                head = head->next;
            }

            int maxSum = 0;
            while(head) {
                int currPairSum = nums.back() + head->val;
                maxSum = max(maxSum, currPairSum);
                nums.pop_back();
                head = head->next;
            }

            return maxSum;
        }
};
