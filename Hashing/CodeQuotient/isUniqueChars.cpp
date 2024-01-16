#include "string"
using namespace std;

bool isUniqueChars(string str) {
    if(!str.length()) return 1;
    int *hash  = new int[256]; 
    for(auto &el : str) {
        hash[el] = 0;
    }
    for(auto &el : str) {
        hash[el] += 1;
    }
    for(auto &el : str) {
        if(hash[el] > 1) {
            delete [] hash;
            return 0;
        }
    }
    delete [] hash;
    return 1;
}

int main (int argc, char *argv[]) {
    
    return 0;
}
