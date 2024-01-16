#include "string"

using namespace std;

int firstUniqueChar(string str) {
    if(!str.length())
        return -1;
    int* freq = new int['z' + 1];
    for(int i = 0; i < 'z' + 1; i++) 
        freq[i] = 0;
    for(char el : str) {
        freq[el] += 1;
    }
    for(int i = 0; i < str.length(); i++) {
        if(freq[str[i]] <= 1)  {
            delete [] freq;
            return i;
        }
    }
    delete [] freq;
    return -1;
}
