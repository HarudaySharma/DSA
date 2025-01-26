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
    ListNode* reverseList(ListNode* head) {
        return recursive(head, nullptr);
        return iterative(head);
    }

    // 1 -> 2 -> 3 -> 4
    ListNode* recursive(ListNode* head, ListNode* prev) {
        if(!head) {
            return nullptr; // in case list is empty
        }
        if(!head->next) {
            head->next = prev; // for tail node (will be the new head node)
            return head;
        }

        ListNode* newHead = recursive(head->next, head);
        head->next = prev;

        return newHead;
    }

    ListNode* iterative(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        // 1 -> 2 -> 3 -> 4
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

            if(!curr->next) {
                head = curr; // for the last node
            }
        }

        return head;
    }
};

