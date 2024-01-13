#include <iostream>
#include <cstring>
#include <stack>
#include <unordered_map>

using namespace std;

class Stack {
private:
    char* arr;
    int capacity;
    int top;

public:
    Stack(int size);
    ~Stack();
    void push(char value);
    char pop();
    char peek();
    bool isEmpty();
};

Stack::Stack(int size) {
    capacity = size;
    arr = new char[capacity];
    top = -1;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(char value) {
    if (top < capacity - 1) {
        arr[++top] = value;
    }
}

char Stack::pop() {
    if (top >= 0) {
        return arr[top--];
    }
    return '\0';
}

char Stack::peek() {
    if (top >= 0) {
        return arr[top];
    }
    return '\0';
}

bool Stack::isEmpty() {
    return top == -1;
}

// For stack operation you can use class named as SimpleStack defined in the head part

string convertToPostfix(const char infix[]) {
    string postfix;
    Stack *s = new Stack(12);
    
    unordered_map<char, int>prec = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {'^', 3},
    };
    
    for(int i = 0; infix[i] != '\0'; i++) {        
        if((infix[i] >= '0' && infix[i] <= '9') || (infix[i] >= 'A' && infix[i] <= 'Z')|| (infix[i] >= 'a' && infix[i] <= 'z'))
            postfix += infix[i];
        else {
            if(s->isEmpty() || infix[i] == '('){
                s->push(infix[i]);
            }
            else {
                if(infix[i] == ')') {
                    while(s->peek() != '('){
                        postfix += s->peek();
                        s->pop();
                    }
                    s->pop();
                    continue;
                }
                if(s->peek() == '(' || prec[s->peek()] < prec[infix[i]]) {
                    s->push(infix[i]);
                }
                else {
                    while(!s->isEmpty() && prec[s->peek()] >=  prec[infix[i]]) {
                        postfix += s->peek();
                        s->pop();
                    }
                    s->push(infix[i]);
                }
            }
        }
    }
    while(!s->isEmpty()){
        postfix += s->peek();
        s->pop();
    }
    return postfix;
}


