#include "iostream"    

double foo (int n, int r) {
    if(r == 0 || n == r) {
        return 1;
    }
    return foo(n-1, r-1) + foo(n-1, r);
}
int main (int argc, char *argv[]) {
    std::cout << argv[1] << argv[2] << "\n";
    std::cout << foo((int)argv[1][0] - '0' , (int)argv[2][0] - '0' )<< "\n";

        return 0;
}
