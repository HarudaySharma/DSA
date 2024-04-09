// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if(!head) return false;

            ListNode* slow = head;
            ListNode* fast = head;
            do {
                slow = slow->next;
                if(!fast || !fast->next)
                    return false;
                fast = fast->next->next;
            } while(slow != fast);
            return true;
        }
};

