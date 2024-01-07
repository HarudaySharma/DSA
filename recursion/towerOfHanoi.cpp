#include "iostream"    

void twh(int n, int a, int b, int c) {
    if(n != 0) {
        twh(n - 1, a, c, b);
        std::cout << "from" << a << "to" << c << "\n";
        twh(n - 1, b, a, c);
    }
}

int main (int argc, char *argv[]) {
    twh(3, 1, 2, 3);
    
    return 0;
}
