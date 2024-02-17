#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int d) {
            data = d;
            next = nullptr;
        }
};

class LinkedList {

    Node *head;
    public:
    LinkedList() {
        head = nullptr;
    }
    Node* getHead(){return head;}
    void setHead(Node *r){ head=r;}

    void insert(int data);
};

void LinkedList:: insert(int data) {
    Node *newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* mergeLinkedLists(LinkedList list1, LinkedList list2){
    LinkedList* mergeList = new LinkedList();
    auto head1 = list1.getHead();
    auto head2 = list2.getHead();
    while(head1 && head2) {
        if(head1->data < head2->data) {
            mergeList->insert(head1->data);
            head1 = head1->next;
        }
        else {
            mergeList->insert(head2->data);
            head2 = head2->next;
        }
    }
    while(head1) {
            mergeList->insert(head1->data);
            head1 = head1->next;
    }
    while(head2) {
            mergeList->insert(head2->data);
            head2 = head2->next;
    }
    auto mHead = mergeList->getHead();
    while(mHead) {
        cout << mHead->data;
        mHead = mHead->next;
        if(mHead)
            cout << " ";
    }
    cout << endl;
    return mergeList->getHead();
}
