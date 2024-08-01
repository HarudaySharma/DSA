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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *evenHead = nullptr;
        ListNode *evenTail = nullptr;

        auto addToEvenLL = [&](ListNode *node) {
            if(!node)
                return;
            if(!evenHead) {
                evenHead = node;
                evenTail = node;
                evenTail->next = nullptr;
                return;
            }
            cout << "EVEN: " << evenTail->val << " | " << node->val;
            cout << endl;
            evenTail->next = node;
            evenTail = evenTail->next;
            evenTail->next = nullptr;
        };

        while(curr) {
            if(curr->next)  {
                prev = curr;
                auto next = curr->next->next;
                addToEvenLL(curr->next);
                curr->next = next;
                curr = curr->next;
            }
            else {
                break;
            }
        }

        if(curr) {
            curr->next = evenHead;
        }
        else
            prev->next = evenHead;

        return head;
    }
};



