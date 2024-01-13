#include<iostream>
#include<cstdio>
#include<cmath>
#include <string.h>
using namespace std;

#define SIZE 100

class PrefixEvaluator {
    private:
        int Stack[SIZE];
        int top;

    public:
        PrefixEvaluator();
        int isFull();
        int isEmpty();
        int push(int item);
        int pop();
        int evalPrefix(char* exp);
};
PrefixEvaluator::PrefixEvaluator() {
    top = -1;
}

int PrefixEvaluator::isFull() {
    return top == (SIZE - 1);
}

int PrefixEvaluator::isEmpty() {
    return top == -1;
}

int PrefixEvaluator::push(int item) {
    if (isFull()) {
        return -1;
    }
    Stack[++top] = item;
    return 0;
}

int PrefixEvaluator::pop() {
    int temp;
    if (isEmpty()) {
        return -1;
    }
    temp = Stack[top--];
    return temp;
}

int evaluate(int b, int a, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return (int) pow(a, b);
    
    }
    return 0;
}

int PrefixEvaluator::evalPrefix(char* exp){
    PrefixEvaluator ev;
    int i = 0;
    while(exp[i] != '\0')
        i++;
    i--;
    while(i >= 0) {
        if(exp[i] >= '0' && exp[i] <= '9') {
            ev.push(exp[i] - '0');
        }
        else {
            ev.push(evaluate(ev.pop(), ev.pop(), exp[i]));
        }
        i--;
    }
    return ev.pop();

}
