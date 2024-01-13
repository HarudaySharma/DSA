#include <string>
#include<cmath>
using namespace std;

class CQStack{
    int maxSize; // size of stack array
    int* stackArray;
    int top; // top of stack

    public:
    // constructor
    CQStack(int s){
        maxSize = s; // set array size
        stackArray = new int[maxSize]; // create array
        top = -1; // no items yet
    }

    // Add element on the top of the stack
    void push(int j);

    // Remove element from the top of the stack
    int pop();

    // Return true is stack is empty
    bool isEmpty();

    // Return true if stack is full
    bool isFull();

};
int CQStack::pop(){
    if (isEmpty()){
        return -1;
    }
    else{
        int temp=stackArray[top--];
        return temp; // access item, decrement top
    }
}
// Return true if stack is full
bool CQStack::isFull(){
    return (top == maxSize-1);
}
bool CQStack::isEmpty(){
    return (top == -1);
}
void CQStack::push(int j){
    if(isFull()){
        return;
    }
    else{
        stackArray[++top] = j; // increment top, insert item
    }
}

/* int pop(), void push(int j) already defined in stack */

int evaluate(int a, int b, char op) {
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
int evalPostfix(CQStack *stack, string exp) {
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] >= '0' && exp[i] <= '9') {
            stack->push(exp[i] - '0');
        }
        else {
            stack->push(evaluate(stack->pop(), stack->pop(), exp[i]));
        }
    }
    return stack->pop();
}
