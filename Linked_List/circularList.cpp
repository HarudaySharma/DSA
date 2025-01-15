#include "bit/stdc++.h"

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data)
        :data(data), next(nullptr), prev(nullptr) {}
};

class CircularList {
public:
    Node* head;
    Node* tail;
    CircularList()
        :head(nullptr), tail(nullptr) {}

    Node* insertEnd(Node* head, int data){
        Node* node = new Node(data);
        if(head == nullptr) {
            head = node;
            tail = node;
            tail->next = head;
            head->prev = tail;
            return head;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
        tail->next = head;
        head->prev = tail;
        return head;
    }
    Node* insertBeg(Node*, int data);
    int isCircularCheck(Node*);
    void deleteBeg();
    void deleteEnd();
    int countNodes();
    void insertSorted(int);
   CircularList* splitLinkedList();


};

CircularList* CircularList::splitLinkedList() {
    CircularList *ls2 = new CircularList();
    if(!head || !head->next)
        return ls2;
    Node* slow = head;
    Node* fast = head;
    Node* prevSlow = nullptr;
    Node* prevFast = nullptr;
    // slow always points to n / 2 + 1 th node
    do {
        prevSlow = slow;
        slow = slow->next;
        prevFast = fast->next;
        fast = fast->next->next;
    } while(fast != head && fast->next != head);

    prevSlow->next = head;

    if(fast->next == head) {
        fast->next = slow;
        ls2->head = slow;
        return ls2;
    }
    // prevFast => tail
    prevFast->next = slow;
    ls2->head = slow;
    return ls2;
}
void CircularList::insertSorted(int data) {
    Node* newNode = new Node(data);
    if(!head) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* tail = head;
    while(tail->next != head) {
        tail = tail->next;
    }

    if(head->data > data) {
        newNode->next = head;
        head = newNode;
        tail->next = head;
        return;
    }
    Node* prev = head;
    while(prev->next->next != head && prev->next->data < data)
        prev = prev->next;

    // two cases =>
    //              1. tail->data >= newData
    //              2. tail->data < newData
    if(prev->next->data >= data) {
        newNode->next = prev->next;
        prev->next = newNode;
        return;
    }
    prev->next->next = newNode;
    newNode->next = head;
    return;
}

int CircularList::countNodes() {
    if(!head)return 0;
    if(head->next == head) return 1;
    int count = 0;
    Node* fast = head;
    do {
        count++;
        fast = fast->next->next;

    } while(fast != head && fast->next != head);
    return fast == head ? count * 2 : count * 2 + 1;


}
void CircularList::deleteBeg() {
    if(!head)
        return;
    if(!head->next) {
        delete head;
        head = nullptr;
    }
    Node* tail = head;
    while(tail->next != head)
        tail = tail->next;
    Node* temp = head;
    head = head->next;
    delete temp;
    tail->next = head;
}

void CircularList::deleteEnd() {
    if(!head)
        return;
    if(!head->next) {
        delete head;
        head = nullptr;
    }

    Node* prevTail = head;
    while(prevTail->next->next != head)
        prevTail = prevTail->next;

    Node* tail = prevTail->next;
    prevTail->next = head;
    delete tail;
}

Node* CircularList::insertBeg(Node* head, int data) {
    // for singly Linked List
    Node* node = new Node(data);
    if(!head) {
        head = node;
        head->next = head;
        return head;
    }

    Node* tail = head;
    while(tail->next != head)
        tail = tail->next;

    node->next = head;
    head = node;
    tail->next = node;
    tail = node;
    return head;
}

int CircularList::isCircularCheck(Node* head) {
    if(!head || head->next->next == head)
        return 1;

    Node* slow = head;
    Node* fast = head;
    Node* prevFast = nullptr;
    do {
        if(!fast || !fast->next)
            return 0;
        slow = slow->next;
        prevFast = fast->next;
        fast = fast->next->next;
        if(slow == fast){
            return 0;
        }
    }while(prevFast != head && fast != head);

    return 1;
}

int main (int argc, char *argv[]) {

    return 0;
}

