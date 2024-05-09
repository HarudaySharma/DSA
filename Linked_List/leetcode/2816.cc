#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        int carry = 0;
        ListNode* hd = nullptr;

        ListNode* doubleIt(ListNode* head) {
            if(hd == nullptr)
                hd = head;
            if(!head) {
                return head;
            }
            doubleIt(head->next);
            int newVal = head->val * 2 + carry;
            carry = newVal / 10;
            head->val = newVal % 10;
            if(head == hd && carry != 0) {
                ListNode *newHead = new ListNode(carry);
                newHead->next = head;
                return newHead;
            }
            return head;
        }
};

