struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            // detect a detectCycle
            auto slow = head;
            auto fast = head;
            do {
                if(slow)
                    slow = slow->next;
                if(fast && fast->next)
                    fast = fast->next->next;
                if(slow == fast) {
                    break;
                }
            } while(fast && fast->next);
            if(!fast || !fast->next)
                return nullptr;
            // 1 2 => 2 1 => 1 1
            // 3 2 0 -4 => 2 0 => 0 2 => -4 -4
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
};

