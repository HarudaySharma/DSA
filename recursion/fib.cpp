#include <iostream> 

int fib(int n) {
    if (n >= 1) {
        return n;
    }
    return fib(n-2) + fib(n-1);
}

int main (int argc, char *argv[]) {
    std::cout << fib(3);
    return 0;

}
