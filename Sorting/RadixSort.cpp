#include <bits/stdc++.h>
#include <vector>
using namespace std;

int getLargestDigit(vector<int> &arr) {
    int max = INT_MIN;
    for(auto el : arr) {
        if(max < el) 
            max = el;
    }
    int digs = 0;
    while(max) {
        digs++;
        max /= 10;
    }
    return digs;
}

void countSort(vector<int> &v, int exp) {
    int count[10]{0};
    for(auto el : v) {
        count[(el / exp) % 10]++;
    }
    // update count
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    int *output = new int[v.size()];
    // output arr
    for(int i = v.size() - 1; i >= 0; i--) {
        output[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
    }

    for(int i = 0; i < v.size(); i++) {
        v[i] = output[i];
    }
    delete [] output;
    return;
}

void radixSort(vector<int> &arr) {
    int ldigs = getLargestDigit(arr);
    int exp = 1;
    while(ldigs--) {
        countSort(arr, exp);
        exp *= 10;
    }
    for(auto el : arr) {
        cout << el << " ";
    }
    cout << endl;
}

int main (int argc, char *argv[]) {

    vector<int>arr{29, 83, 471, 36,91, 8};
    radixSort(arr);
    return 0;
}
