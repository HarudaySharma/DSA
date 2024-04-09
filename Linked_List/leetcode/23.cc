#include <bits/stdc++.h>
#include <climits>
#include <list>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class compare{
    public:
        bool operator()(const ListNode *a, const ListNode *b) const{
            return a->val > b->val;
        }
};
class Solution {
public:
    ListNode* usingPriorityQueue(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(auto list : lists) {
            while(list) {
                pq.push(list);
                list = list->next;
            }
        }
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if(!head) {
                head = top;
                tail = top;
            }else {
                tail->next = top;
                tail = top;
            }
            top->next = nullptr;
        }
        return head;
    }

    int findMin(vector<ListNode*>& lists) {
        int min = INT_MAX;
        int minIdx = -1;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] && lists[i]->val < min) {
                min = lists[i]->val;
                minIdx = i;
            }
        }
        return minIdx;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while(1) {
            int idx = findMin(lists);
            if(idx == -1)
                break;
            // detach the node form lists
            auto node = lists[idx];
            lists[idx] = lists[idx]->next;
            node->next = nullptr;
            // append the node to the mergedList
            if(!head) {
                head = node;
                tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
        }
        return head;
        // using priority_queue ?
        // return usingPriorityQueue(lists);
    }
};

