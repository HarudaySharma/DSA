#include "iostream"

using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int data) 
            :data(data) ,prev(nullptr), next(nullptr){}
};

class DoubleLinkedList {
   public:
       Node* head ;
       Node* tail ;
       DoubleLinkedList() {
           head = nullptr;
           tail = nullptr;
       }
       void insertEnd(int data) {
          Node* node = new Node(data);
          if(head == nullptr && tail == nullptr) {
              tail = node;
              head = node;
              return;
          }
          node->prev = tail;
          tail->next = node;
          tail = node;
       }
       void forwardPrint() {
           Node* curr = head;
           while(curr) {
               cout << curr->data << " ";
               curr = curr->next;
           }
       cout << "\n";
       }
       Node* rotateByK(Node* head, int k);
       Node* rearrangeList(Node*);


};
Node* DoubleLinkedList::rotateByK(Node* head, int k) {
    // finding length of the list;
    // and getting the tail of the list
    
    if(!head || !head->next) {
        return head;
    }

    Node* fast = head;
    Node* tail = head;
    int len = 0;
    
    while (fast && fast->next) {
       len += 1; 

       if(!fast->next->next )
           tail = fast->next;

       fast = fast->next->next;

    }
    if(!fast) 
        len *= 2;
    else {
        tail = fast;
        len = len * 2 + 1;
    }
    
    k = (k >= len) ? k % len : k;
    if(k == 0) {
        return head;
    }

    tail->next = head;
    head->prev = tail;
    while(--k) {
        tail = tail->prev;
    }
    tail->prev->next = nullptr;
    head = tail; 
    head->prev = nullptr;
    return head;

}     

Node* rearrangeList(Node* head) {
    if(!head || !head->next)
        return head;
    Node* firstOdd = head;
    Node* lastEven = head->next;
    Node* lastOdd = firstOdd;
    Node* curr = head->next->next;
    int count = 3;
    head = lastEven;
    lastEven->prev = nullptr;
    while(curr) {
        if(count % 2 == 0){ 
            lastEven->next = curr;
            curr->prev = lastEven;
            lastEven = curr;
        }
        else {
         lastOdd->next = curr;
         curr->prev = lastOdd;
         lastOdd = curr;
        }
        count++;
        curr = curr->next;
    }
    lastEven->next = firstOdd;
    lastOdd->next = nullptr;
    return head;
}
    
int main (int argc, char *argv[]) {
    DoubleLinkedList ls;
    int n;
    cin >> n;
    while (n--) {
        int ele;
        cin >> ele;
        ls.insertEnd(ele);
    }
    cout << "rotation by: ";
    int rot;
    cin >> rot;
    Node* head = ls.rotateByK(ls.head, rot);
    ls.forwardPrint();
    return 0;
}
