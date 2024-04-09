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
    ListNode* reverseKGroup(ListNode* head, int &k) {
        ListNode* newHead = nullptr;
        ListNode *prevWindowTail = nullptr;
        ListNode *currWindowHead = nullptr;
        // counting the number of nodes to consider
        int nodeCount = 0;
        ListNode *curr = head;
        while(curr) {
            nodeCount ++;
            curr = curr->next;
        }
        nodeCount = nodeCount - (nodeCount % k);
        curr = head;
        ListNode *prev = nullptr;
        int windowSize = 0;
        // traversing the list & updating links.
        while(curr && nodeCount-- >= 0) {
            windowSize += 1;
            if(windowSize > k) {
               // cout << "cwh : " << currWindowHead->val;
               // cout << " -> " << curr->val << endl;
                currWindowHead->next = curr;
                prev  = nullptr;
                windowSize = 1;
            }
            if(windowSize == 1) {
                currWindowHead = curr;
            }
            if(windowSize == k) {
               // cout << "pwt : " << (prevWindowTail ? to_string(prevWindowTail->val) : "NULL");
               // cout << " -> " << curr->val << endl;
                if(prevWindowTail) {
                    prevWindowTail->next = curr;
                }
                prevWindowTail = currWindowHead;
                if(!newHead)
                    newHead = curr;// last node (1st window)
            }
            //cout << "curr " << curr->val;
            //cout << " -> prev " << (prev ? to_string(prev->val): "NULL");
            //cout << endl;
            ListNode *nxt = curr->next;
            if(prev)
                curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        if(nodeCount == 0)
            currWindowHead->next = nullptr;
        //head = newHead;
        //while(head) {
        //    cout << head->val << " ";
        //    head = head->next;
        //}
        //cout << endl;
        return newHead;
    }
};

