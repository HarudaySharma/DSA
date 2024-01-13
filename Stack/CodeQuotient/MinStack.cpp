#include "stack"

using namespace std;

class MinStack {
    private:
        stack<int> mainStack;
        stack<int> minStack;

    public:
        void push(int item);
        int pop(); 
        int getMin(); 
};

int MinStack::getMin() {
    if(minStack.empty())
        return -1;

    return minStack.top();
}

int MinStack::pop() {
    if(mainStack.empty())
        return -1;

    int item = mainStack.top();
    if(item == minStack.top())
        minStack.pop();
    mainStack.pop();

    return item;
}
void MinStack::push(int item) {
    mainStack.push(item);
    if(minStack.empty() || minStack.top() >= item)
        minStack.push(item);

    return;

}
