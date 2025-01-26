#include "bits/stdc++.h"

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};


class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        if(!head || !head->next) {
            return;
        }

        // using fast and slow pointers
        Node* fast = head;
        Node* slow = head;

        do {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) break; // loop found

        } while(fast && fast->next);

        // if no loop (cycle) is present
        if(!fast || !fast->next || (slow != fast)) {
            return;
        }

        // cycle is present
        // start the slow from head
        // move the slow and fast pointer ahead one node at a time
        // till the next pointers of slow and fast are not pointing to same node
        // at that time the fast pointer will be pointing to the node
        // from which the cycle started

        slow = head;

        // this check is needed when slow and fast both meet
        // at the head of the LL
        if (slow == fast) {
            while (fast->next != slow) {
                fast = fast->next;
            }
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        fast->next = nullptr;

        return;
    }
};

