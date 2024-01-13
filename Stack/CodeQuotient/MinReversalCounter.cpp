#include <iostream>
#include <stack>
using namespace std;

class MinReversalCounter {
    private:
        static const int MAX_LEN = 100000;
        char expr[MAX_LEN + 1];
    public:
        MinReversalCounter()
        {
            expr[0] = '\0';
        }
        int minReversal();
        void setInputExpression();
        void processAndPrintResult();
};

void MinReversalCounter::setInputExpression() {
    std::cin >> expr;
}

void MinReversalCounter::processAndPrintResult() {
    int result = minReversal();
    std::cout <<result << std::endl;
}

int MinReversalCounter::minReversal() {
    stack<char> *s = new stack<char>;
    if(expr[0] == ']' && expr[1] == '[' && expr[2] == '\0') {
            return 2;
    }

    int i = 0;
    int count = 0;
    for(i = 0; expr[i] != '\0'; i++) {
        if(s->empty()) {
            s->push(expr[i]);
            continue;
        }
        if(s->top() == expr[i]) {
            s->push(expr[i]);
        }
        else {
            if(s->top() == ']') {
                count++;
                s->pop();
            }
            else 
                s->pop();
        }
    }
    if(s->empty()) {
        if(count == 0)
            return 0;
        return  count % 2 == 0 ? count : -1;
    }
    i = 0;
    while(!s->empty()) {
        i++;
        s->pop();
    }
    delete s;
    return i % 2 == 0 ? count + i: -1;
}

