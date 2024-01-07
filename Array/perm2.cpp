#include "iostream"

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void permut(char* str, int low, int high) {

    if(low == high) {
        std::cout << str << "\n";
        return;
    }

    for(int i = low; i < high; i++) { 
        if(i != low) 
            swap(str[i], str[low]);
        permut(str, low + 1, high);
        if(i != low) 
            swap(str[i], str[low]);
    }
}

int main (int argc, char *argv[]) {
    int high = 0;
    for (; argv[1][high] != '\0'; high++){} 
    permut(argv[1], 0, high);
    return 0;
}
