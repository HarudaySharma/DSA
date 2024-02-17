#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insertNode(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

   
    void rotateList(int k);
    void print();
};
void LinkedList::print() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* tail = nullptr;
int findSize(Node* head) {
    Node* fast = head;
    tail = head;
    int size = 0;
    while(fast && fast->next)  {
        size++;
        tail = fast->next;
        fast = fast->next->next;
    }
    tail = fast ? fast : tail;
    return fast ? size * 2 - 1 : size * 2;
}

void LinkedList::rotateList(int k) {
    int size = findSize(head);
    if(k > size)
        return;
    k--;
    auto target = head;
    while(target && k--) {
        target = target->next;
    }
    if(!target)
        return;
    tail->next = head;
    head = target->next;
    target->next = nullptr;
}

