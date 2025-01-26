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
private:

    ListNode *mergedHead = nullptr;
    ListNode *mergedTail = nullptr;

public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;

        while(head1 && head2) {
            if(head1->val < head2->val) {
                addToTail(head1);
                head1 = head1->next;
            } else {
                addToTail(head2);
                head2 = head2->next;
            }
        }

        while(head1) {
            addToTail(head1);
            head1 = head1->next;
        }
        while(head2) {
            addToTail(head2);
            head2 = head2->next;
        }

        return mergedHead;
    }

private:

    void addToTail(ListNode *head) {
        if(!mergedHead) {
            mergedHead = head;
            mergedTail = head;
            return;
        }
        mergedTail->next = head;
        mergedTail = head;

        return;
    }

};


