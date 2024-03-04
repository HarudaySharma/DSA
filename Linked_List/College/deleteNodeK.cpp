#include "bits/stdc++.h"

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data)
        :data(data), next(nullptr) {}
};

class CircularList {
private:
        Node* deleteNextNode(Node*);
public:
    Node* head;
    Node* tail;
    CircularList()
        :head(nullptr), tail(nullptr) {}

    void insertEnd(int data){
        Node* node = new Node(data);
        if(head == nullptr) {
            head = node;
            tail = node;
            tail->next = head;
            return;
        }
        tail->next = node;
        tail = node;
        tail->next = head;
        return;
    } 
    void deleteK(Node*, int);
    void display();

};

// @return
// data of the node deleted or -1 if single node present
Node* CircularList::deleteNextNode(Node* node) {
    Node* target = node->next;
    if(node == target) {
        return nullptr;
    }
    if(target == head) {
        tail->next = head->next;
        const int data = head->data;
        delete head;
        head = tail->next;
    }
    if(target == tail) {
        node->next = head;
        tail = node;
        const int data = target->data;
        delete target;
    }
    else {
        node->next = target->next;
        const int data = target->data;
        delete target;
    }
    return node->next;
}

void CircularList::deleteK(Node* head, int k) {
    int i = 1;
    Node* curr = head;
    while(i < k - 1) {
        curr = curr->next;
        i++;
    }
    Node* nxtNode = deleteNextNode(k == 1 ? tail : curr);
    if(!nxtNode) {
        return;
    }
    return deleteK(nxtNode, k);
}

void CircularList::display() {
    if(!head)
        std::cout << "Empty" << std::endl;
    Node* curr = head;
    do {
        std::cout << curr->data << " ";
        curr = curr->next;
    } while(curr != head);
    std::cout << std::endl;
    return;
}
int main (int argc, char *argv[]) {
    CircularList ls;
    int n;
    std::cin >> n;
    int i = 0;
    while(i < n) {
        ls.insertEnd(i);
        i++;
    }
    int k;
    std::cin >> k;
    ls.deleteK(ls.head, k);
    std::cout << "list" << std::endl;
    ls.display();
    return 0;
}
