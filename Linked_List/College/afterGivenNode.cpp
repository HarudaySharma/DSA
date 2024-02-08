#include <cstdlib>
#include <iostream>
#include <vector>

class Node {
public:
    int data;
    Node *next = nullptr;

    Node(int data) 
        : data(data), next(nullptr) {}

};

class LinkedList {
public:
    Node *head;
    Node *tail;

    LinkedList()
        :head(nullptr), tail(nullptr){}

    void insertEnd(int data) {
        Node *New = new Node(data);
        if (head == nullptr) {
            head = tail = New;
            return;
        }
        tail->next = New;
        tail = New;
    }

    void attachNode(Node* node) {
        tail->next = node;
        tail = node;
    }

    void insertBeforeNode(int data ,Node* target) {
        Node* newNode = new Node(data);
        Node* curr = head;
        while(curr && curr->next != target) {
            curr = curr->next;
        }
        if(!curr) {
            delete newNode;
            return;
        }
        newNode->next = target;
        curr->next = newNode;
    }
    void insertBeforeElement(int data ,int target) {
        Node* newNode = new Node(data);
        Node* curr = head;
        while(curr && curr->next && curr->next->data != target) {
            curr = curr->next;
        }
        if(!curr->next) {
            delete newNode;
            return;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void display() {
        Node* curr = head;
        while(curr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

int main (int argc, char *argv[]) {
    LinkedList* list = new LinkedList();
    list->insertEnd(10);
    list->insertEnd(20);
    list->insertEnd(30);
    Node* node = new Node(40);
    list->attachNode(node);
    list->display();
    list->insertBeforeElement(25, 20);
    list->insertBeforeNode(35, node);
    list->display();

    return 0;
}


