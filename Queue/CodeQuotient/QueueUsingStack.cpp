#include<iostream>
#include<cstdio>

using namespace std;
class CQStack
{
    public:
        int maxSize; // size of stack array
        int stackArray[100];
        int top; // top of stack
        CQStack();
        void push(int j);
        int pop();
        bool isEmpty();
        bool isFull();
};

CQStack::CQStack() // constructor
{
    maxSize=100;
    top = -1; // no items yet
}
void CQStack::push(int j) // put item on top of stack
{
    if(isFull())
        return;
    else
    {
        top++;
        stackArray[top] = j; // increment top, insert item
    }
}
int CQStack::pop() // take item from top of stack
{
    if (isEmpty())
        return -1;
    else
    {
        int temp=stackArray[top--];
        return temp; // access item, decrement top
    }
}
bool CQStack::isEmpty() // true if stack is empty
{
    return (top == -1);
}
bool CQStack::isFull() // true if stack is full
{
    return (top == maxSize-1);
}

void enqueue(CQStack *st1, CQStack *st2, int item) {
    if(st1->isFull())
        return;
    st1->push(item);

}

int dequeue(CQStack *st1, CQStack *st2) {
    if(st2->isEmpty()){
        while(!st1->isEmpty())
            st2->push(st1->pop());
    }
    return st2->pop();

}
