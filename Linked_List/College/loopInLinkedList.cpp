#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int data = 0, Node *next = nullptr) : data(data), next(next) {}
};

class LinkedList {
    private:
        Node *head;
        Node *tail;

    public:
        LinkedList() : head(nullptr), tail(nullptr) {}

        Node* insertNode(int data, Node* next = nullptr) {
            Node* newN = new Node(data, next);
            if(!head) {
                head = newN;
                tail = newN;
                return newN;
            }
            tail->next = newN;
            tail = newN;
            return newN;
        }
 
        bool detectLoop() {
            Node* slow = head;
            Node* fast = head;
            bool loopFound = false;
            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast) {
                    loopFound = true;
                    break;
                }
            }
            if(loopFound) {
                Node* curr = head;
                while(slow->next->next != curr->next->next){
                    slow = slow->next;
                    curr = curr->next;
                }
                //slow and curr are at head
                if(slow == curr) {
                    tail->next = nullptr;
                    return true;
                }
                slow->next = nullptr;
                return true;
            }
            return false;
        }
};

int main(int argc, char *argv[]) {
    LinkedList l;
    l.insertNode(1);
    l.insertNode(2);
    Node* n = l.insertNode(3);
    l.insertNode(4);
    l.insertNode(5);
    l.insertNode(6);
    l.insertNode(7);
    l.insertNode(8, n);
    cout << l.detectLoop();
    return 0; 
}
