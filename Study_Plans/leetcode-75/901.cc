#include <stack>
using namespace std;

class StockSpanner {
    stack<pair<int, int>> prices;

public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        while(!prices.empty() && prices.top().first <= price) {
            span += prices.top().second;
            prices.pop();
        }
        prices.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

