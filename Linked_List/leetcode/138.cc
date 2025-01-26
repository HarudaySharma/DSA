// Definition for a Node.
#include <unordered_map>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
    public:
        Node *copyRandomList(Node *head) {
            unordered_map<Node *, Node *> copy;
            Node *curr = head;

            Node *newHead = nullptr;
            Node *newTail = nullptr;

            while (curr) {
                // check copy of current in hashmap
                Node *newCurr = nullptr;
                if (copy.count(curr)) {
                    newCurr = copy[curr];
                } else {
                    newCurr = new Node(curr->val);
                    copy[curr] = newCurr;
                }

                // update the head and tail of new list
                if(!newHead) {
                    newHead = newCurr;
                    newTail = newCurr;
                }
                else {
                    newTail->next = newCurr;
                    newTail = newCurr;
                }

                // check for the random;
                Node *newRandom = nullptr;
                if (copy.count(curr->random)) {
                    newRandom = copy[curr->random];
                } else if (curr->random != nullptr) {
                    newRandom = new Node(curr->random->val);
                    copy[curr->random] = newRandom;
                }

                newCurr->random = newRandom;
                curr = curr->next;
            }

            return newHead;
        }
};
