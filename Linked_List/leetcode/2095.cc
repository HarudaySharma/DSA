#include <bits/stdc++.h>
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
    ListNode* deleteMiddle(ListNode* head) {
        auto fast = head;
        auto slow = head;
        ListNode* prevSlow = nullptr;

        while(fast && fast->next) {
            fast = fast->next->next;
            prevSlow = slow;
            slow = slow->next;
        }

        if(!prevSlow) {
            delete head;
            return nullptr;
        }

        prevSlow->next = slow->next;
        delete slow;
        return head;
    }
};

