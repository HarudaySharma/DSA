#include <bits/stdc++.h>
#include <climits>
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
        int mx = INT_MIN;
        void deleteNode(ListNode *prev) {
            // delete that ListNode
            ListNode *tmp = prev->next;
            prev->next = prev->next->next;
            delete tmp;
        }
        void rec(ListNode *curr) {
            if(!curr) {
                return;
            }
            rec(curr->next);
            if(curr->next && curr->next->val < mx) {
                deleteNode(curr);
            }
            mx = max(mx, curr->val);
            return;
        }
        ListNode* removeNodes(ListNode* head) {
            ListNode* curr = head;
            rec(head);
            if(head->val < mx) {
                curr = head;
                head = head->next;
                delete curr;
            }
            return head;
        }
};

