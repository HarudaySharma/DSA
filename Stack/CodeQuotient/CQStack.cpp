#include <string>
using namespace std;

class CQStack {
  public: int maxSize; // size of stack array
          int stackArray[1000];
          int top; // top of stack

          CQStack(int s);
          void push(int j);  
          int pop();
          int isEmpty();
          int isFull();
          string reverseString(string s);

};

CQStack::CQStack(int s) {
    maxSize = s;
    top = -1;
}

void CQStack::push(int ele) {
    if(top >=  maxSize) {
        return;
    }
    stackArray[++top] = ele;
}

int CQStack::pop() {
    if(top == -1) {
        return -1;
    }
    return stackArray[top--];
}

int CQStack::isEmpty() {
    return top == -1 ? 1 : 0;
}

int CQStack::isFull(){
    return top == maxSize ? 1 : 0;
}

string CQStack::reverseString(string s) {
    for(auto ch : s){
        this->push(ch);
    }
    string rev = "";
    while (!this->isEmpty()) {
        rev += this->pop();
    }
    return rev;
}
