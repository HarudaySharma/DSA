#include <bits/stdc++.h>
#include <climits>
using namespace std;

string isFair(int *arr) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    for(int i = 0; i < 4; i++) {
        if(arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] != max1 && arr[i] > max2)
            max2 = arr[i];
    }
    int c1 = max(arr[0], arr[1]);
    int c2= max(arr[2], arr[3]);
    return c2 != max1 && c2 != max2 ? "NO" : c1 != max1 && c1 != max2 ? "NO" : "YES";

}
int main (int argc, char *argv[]) {
    int t;
    cin >> t;
    while(t--) {
        int arr[4];
        for(int i = 0; i < 4; i++) {
            cin >> arr[i];
        }
        cout << isFair(arr) << endl;
    }


    return 0;
}
