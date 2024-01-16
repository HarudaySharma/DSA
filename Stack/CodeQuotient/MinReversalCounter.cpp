#include <iostream>
#include <ostream>
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
    int open = 0;
    int close = 0;
    for(int i = 0; expr[i] != '\0'; i++) {
        if(expr[i] == '[') {
            if(close)close--;
            else open++;
        }
        else {
            if(open) open--;
            else close++;
        }
    }
    std::cout << open << std::endl;
    std::cout << close << std::endl;
    if(!open)
        return 0;
    if(!close) 
        return open % 2 == 0 ? open / 2 : -1;
    return abs(open + close) % 2 == 0 ? abs(open + close) : -1;
    
}
/*
 * if([):
 *  open++;
 * if(])
 *
*/
