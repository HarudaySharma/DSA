#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        Node* prev;
        int data;
        Node *next;
        Node(int data = 0, Node* prev = nullptr, Node *next = nullptr) 
            : data(data), prev(prev), next(next) {}
};

class LinkedList {
    private:
        Node *head;
        Node *tail;

    public:
        LinkedList() : head(nullptr), tail(nullptr) {}

        Node* insertNode(int data, Node* prev = nullptr, Node* next = nullptr) {
            Node* newN = new Node(data, prev, next);
            if(!head) {
                head = newN;
                tail = newN;
                return newN;
            }
            tail->next = newN;
            newN->prev = tail;
            tail = newN;
            return newN;
        }
        //Double the last digit and subtract it from a number made by the other digits.
        //The result must be divisible by 7. (We can apply this rule to that answer again)
        bool isDivisibleBy_7() {
            while(head != tail) {
                int dbl = tail->data * 2;
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;

                int num = tail->data;
                Node* curr = tail;
                while(curr->prev && num < dbl) {
                    num += (curr->prev->data * 10);
                }
                num -= dbl;
                curr = tail;
                while(num){
                    curr->data = (num % 10);
                    curr = curr->prev;
                    num /= 10;
                }
            }
            return head->data % 7 == 0;
        }
};

int main(int argc, char *argv[]) {
    // 9298886261
    string num;
    cin >> num;
    LinkedList l;
    for(auto n : num) {
        l.insertNode(n - '0');
    }
    
    cout <<  l.isDivisibleBy_7();
    return 0; 
}
