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

    void forwardPrint(){
        Node *first = head;
        while(first) {
            std::cout << first->data << "-";
            first = first->next;
        }
    }

    void backwardPrint(Node *head) {
        if(!head)
            return;
        backwardPrint(head->next);
        std::cout << head->data << "-";

    }
    Node* copyList(Node *head) {
        LinkedList *ls =  new LinkedList();
        while(head){
            ls->insertEnd(head->data);
            head = head->next;
        }
        return ls->head;
    }

    void shiftSmallLarge();
    Node* getMaxNode(Node**);
    Node* getMinNode(Node**);
    Node* getTail();
    int checkPalindrome();
    void shiftMinToHead(Node*, Node**);
    void shiftMaxToTail(Node*, Node**, Node**);
    int loopInList(Node*);
    void reverseList();
    LinkedList addListNumbers(LinkedList& l2);
    void deleteNode(Node* target);
    void swapTwoNodes(int, int);
};

Node* LinkedList::getMaxNode(Node** prev){
    // h ==> head ==> node
    Node* curr = (*prev)->next;
    Node* max = (*prev);
    while(curr){
       if(max->data < curr->data) 
           max = curr;
       curr = curr->next;
    }
    return max ;
}

Node* LinkedList::getMinNode(Node** prev){
    Node* curr = (*prev)->next;
    Node* min = *(prev);
    while(curr){
       if(min->data > curr->data) 
           min = curr;
       curr = curr->next;
    }
    return min;
}

Node* LinkedList::getTail() {
    Node* curr = head;
    while(curr->next){
        curr = curr->next;
    }
    return curr;
}

void LinkedList:: shiftMinToHead(Node* min, Node** head){
    if(min == *head)
        return;
    Node *prev = *head;
    while(prev->next != min)
        prev = prev->next;

    prev->next = min->next;
    min->next = *head;
    *head = min;

}
void LinkedList::shiftMaxToTail(Node* max, Node** head, Node** tail){
    if(max == *tail)
        return;
    if(max == *head){
        *head = max->next;
        max->next = *tail;
        *tail = max;
        return;
    }
    Node* prev = *head;
    while(prev->next != max)
        prev = prev->next;
    prev->next = max->next;
    (*tail)->next = max;
    max->next = nullptr;
}
void LinkedList::shiftSmallLarge() {
    if(!head || !head->next)
        return;
    Node* min = getMinNode(&(this->head));
    shiftMinToHead(min, &head);
    Node* max = getMaxNode(&(this->head));
    Node* tail = getTail();
    shiftMaxToTail(max, &head, &tail);
}

int LinkedList::checkPalindrome() {
    //using Stack
    //filling till not at head not at mid
    if(!head)
        return 0;

    std::vector<decltype(head->data)>*Stack = new vector<decltype(head->data)>;
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        Stack->push_back(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast && !fast->next)
        slow = slow->next;

    while(slow){
        if (slow->data != Stack->back())
            return 0;
        Stack->pop_back();
        slow = slow->next;
    }
    return 1;

}

int LinkedList::loopInList(Node *head) {
    Node* slow = head;
    Node* fast = head;

    do {
        if(!fast || !fast->next)
            return 0;
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast);

    slow = head;
    int count = 0;
    while(1){
        if(slow == fast ){
            if(count == 0)
                count = 1;
            else
             break;
        }
        if(count)
            count++;
        slow = slow->next;
    }
    // 0-based indexing ? count - 1 : count;
    return count;
} 

void LinkedList::reverseList() {
    // as function not taking any arguments => no recursion
    // using sliding pointers
    if(!head || !head->next)
        return;

    Node* prev = nullptr;
    Node* curr = head;
    Node* next = head->next;

    while(next) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    head = curr;
    return;
}

LinkedList LinkedList::addListNumbers(LinkedList& l2){
   LinkedList *res = new LinkedList();
   Node *head1 = head;
   Node* head2 = l2.head;
   int carry = 0;
   while(head1 && head2) {
       int sum = head1->data + head2->data + carry;
       res->insertEnd(sum % 10);
       carry = sum / 10;
       head1 = head1->next;
       head2 = head2->next;
   }
   if(head1){    
       while (head1) {
           int sum = head1->data + carry;
           res->insertEnd(sum % 10);
           carry = sum / 10;
           head1 = head1->next;
       }
   }
   else {
       while (head2) {
           int sum = head2->data + carry;
           res->insertEnd(sum % 10);
           carry = sum / 10;
           head2 = head2->next;
       }
   }   
   if(carry)
       res->insertEnd(carry);
   return *res;
}

void LinkedList::deleteNode(Node* target){
    if(!head || !head->next)
        return;

    if(head == target) {
        delete head;
        head = head->next;
        return;
    }

    Node* curr = this->head;
    while(curr && curr->next){
        if(curr->next == target && curr->next->next != nullptr){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            return; 
        }
        curr = curr->next;
    }
}
void LinkedList::swapTwoNodes(int x, int y) {
    if(!head || !head->next)
        return;
    Node* curr = head;
    Node* prevX = nullptr;
    Node* prevY = nullptr;
    if(head->data == x || head->data == y) {
        int key = head->data == x ? y : x;

        while(curr && curr->next ){
            if(curr->next->data == key) {
                break;
            }
            curr = curr->next;
        }
        if(!curr || !curr->next)
            return;
        Node* target = curr->next;
        curr->next = head;
        Node *targetNext = target->next;
        target->next = head->next;
        head->next = targetNext;
        head = target;
        return;
    }
    while(curr && curr->next) {
        if(curr->next->data == x) {
            prevX = curr;
        }
        if(curr->next->data == y) {
            prevY = curr;
        }
        if(prevX && prevY) 
            break;
        curr = curr->next;
    }
    if(!prevX || !prevY) 
        return;
    Node *X = prevX->next;
    Node *Y = prevY->next;
    prevX->next = Y;
    prevY->next = X;
    Node *Xnext = X->next;
    X->next = Y->next;
    Y->next = Xnext;

    return;
    
}

int main (int argc, char *argv[]) {
    int choice = 0;
    LinkedList *ls = new LinkedList;

    while(1) {
        std::cout << "Menu :" << "\n";
        std::cout << "1: " << "insertEnd" << "\n";
        std::cout << "2: " << "forwardPrint"<< "\n";
        std::cout << "3: " << "backwardPrint" << "\n";
        std::cout << "-1: " << "Exit" << "\n";
        std::cin >> choice;
        std::cout << "\n";
        switch (choice) {
           case 1: 
               int ele;
               std::cout << "Element: ";
               std::cin >> ele;
               std::cout << "\n";
               ls->insertEnd(ele);
               break;
           case 2: 
               ls->forwardPrint();
               break;
           case 3: 
               ls->backwardPrint(ls->head);
               break;
           case -1:
               std::exit(0);
        default:
            
            break;
       } 
    }
    return 0;
}
