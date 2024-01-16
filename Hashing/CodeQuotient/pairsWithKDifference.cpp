#include <algorithm>
#include <asm-generic/errno.h>
#include <cstdlib>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <ostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int getI(int k, int x) {
    return  abs(k + x);
}

int getJ(int k, int x) {
   return abs(k - getI(k, x)); 
}

int getKey2(int x, int k) {
    return x - k;
}

int getKey1(int x, int k) {
   return x + k;
}

int getPairsCount2(int arr[], int n, int k) {
    sort(arr, arr + n);
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < n && j < n) {
        int res = arr[j] - arr[i] ;
        if(res - k == 0){
            count++;
            i++, j++;
        }
        else {
            if(res - k < 0) {
                j++;
            }
            else {
                i++;
            }
        }
    }
    return count;
}
int getPairsCount(int arr[], int n, int k) {
    // hash function => abs(k - x);

    int max = arr[0] ;
    int min = arr[0];
    for(int i = 1 ; i < n; i++){
        if(max < arr[i]) max = arr[i];
        if(min > arr[i]) min = arr[i];
    }
    int size = abs(k + max) < abs(k + min) ? abs(k + min) + 1: abs(k + max) + 1;
    //std::cout << "size: " << size << std::endl;

    std::forward_list<int> **hash = new std::forward_list<int>*[size];

    for (int i = 0; i < size; i++) {
     //   cout << "here";
        hash[i] = new std::forward_list<int>();
    }
    for(int i = 0; i < n; i++) {
        int k = getI(k, arr[i]);

        cout << "k" << k ;
        k %= size;
        if(hash[k]->empty()) {
            hash[k]->push_front(arr[i]);
        }
        else {
            hash[k]->push_front(arr[i]);

//           std::cout << "finding correct position" << "\n";

           auto curr = hash[k]->begin();
           if(*curr >= arr[i]){
               hash[k]->push_front(arr[i]);
           }
           else {
               while(std::next(curr) != hash[k]->end() ){
                   if(*(std::next(curr)) >= arr[i]){
                       hash[k]->insert_after(curr, arr[i]);
                       break;
                   }
                   curr++;
               }
               if(std::next(curr) == hash[k]->end()){
                   hash[k]->insert_after(curr, arr[i]);
               }                    
           }
       }
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        int k = getJ(k, arr[i]);
        k %= size;
        if(hash[k]->empty())
            continue;
        auto curr = hash[k]->begin();
        while(curr != hash[k]->end()){
            if(*curr == arr[i] - k) {
                count++;
                break;
            }
            curr++;
        }
    }
    for(int i = 0; i < size + 1; i++) {
        delete hash[i];
    }
    delete[] hash;
    return count / 2;
}

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n, k;
        std::cin >> n >> k;
        int *arr = new int[n];
        for(int i = 0; i < n; i++)
            std::cin >> arr[i];
        std::cout << getPairsCount2(arr, n, k);
    }
}
