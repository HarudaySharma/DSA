#include <iostream>
#include <stack>

using namespace std;


void printNextGreaterElement(int *arr, int n) {
    stack<int> *nextGreater = new stack<int>;
    nextGreater->push(-1);
    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] < arr[i + 1]) {
            nextGreater->push(arr[i+1]);
            continue;
        }            
        if(arr[i] < nextGreater->top()) {
            nextGreater->push(nextGreater->top());
            continue;
        }
        nextGreater->push(-1);
    }
    while (!nextGreater->empty()) {
        std::cout << nextGreater->top() << " "; 
        nextGreater->pop();
    }
    delete nextGreater;
    return;
}

int main (int argc, char *argv[]) {
    return 0;
}
