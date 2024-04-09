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
    private:
        ListNode* deleteNode(ListNode *prev, ListNode *head) {
            if(prev == nullptr) {
                ListNode *tmp = head;
                head = head->next;
                delete tmp;
                return head;
            }
            ListNode* tmp = prev->next;
            prev->next = prev->next->next;
            delete tmp;
            return prev;
        }

    public:
        int middleOfLinkedList(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            // 1 2 3 4 5 6 => 4 // 4
            // 1 2 3 4 5 => 3// 3
            return slow->val;
        }

        ListNode* deleteAllOccurences(ListNode *head, int target) {
            while(head && head->val == target) {
                head = deleteNode(nullptr, head);
            }
            ListNode* tmp = head;
            while(tmp) {
                auto node = tmp->next;
                if(node && node->val == target){
                    deleteNode(node, head);
                }
                tmp = tmp->next;
            }
            return head;
        }
};
