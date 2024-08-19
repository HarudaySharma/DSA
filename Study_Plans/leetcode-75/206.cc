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
        ListNode *reverseList(ListNode *head) {
            if(!head)
                return head;

            auto rec = [&](ListNode *root, auto &&rec) -> ListNode * {
                if (!root->next) {
                    head->next = nullptr;
                    head = root;
                    return root;
                }

                ListNode* next = rec(root->next, rec);
                next->next = root;
                return root;
            };
            rec(head, rec);

            return head;
        }
};
