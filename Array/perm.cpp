#include "string"
#include "iostream"

using namespace std;

void permut(string str, char* res, int *flags, int k) {

    if(k == str.length()) {
        res[k] = '\0';
        std::cout << res << "\n";
        return; 
    }

    for(int i = 0; i < str.length(); i++) {

        if(flags[i] == 0) { 
            flags[i] = 1;
            res[k] = str.at(i);
            permut(str, res, flags, k + 1);
            flags[i] = 0;
        }
    }
}

int main (int argc, char *argv[]) {
    string str (argv[1]); 
    char *res = new char[10];
    int *flags = new int[10];
    for (int i = 0; i < 10; i++) {
        flags[i] = 0;
    }

    permut(str, res, flags, 0);


    return 0;
}
