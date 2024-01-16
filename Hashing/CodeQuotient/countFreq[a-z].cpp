#include <bits/stdc++.h>
using namespace std;

void countFrequency(string str) {
    int hash[27]{0};
    for(auto el : str) {
        hash[el - 'a'] += 1;
    }
    for(int i = 0; i < str.length(); i++) {
        if(hash[str.at(i) - 'a'] != -1) {
            if(i != 0) cout << " ";
            cout << str.at(i) << hash[str.at(i) - 'a'];
            hash[str.at(i) - 'a'] = -1;
        }
    }
    return;

}

int main (int argc, char *argv[]) {
    
    return 0;
}
