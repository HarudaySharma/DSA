#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int l, int mid, int h) {
    vector<int> fHalf;
    int i;
    for (i = l; i <= mid; i++) {
        fHalf.push_back(arr[i]);
    }
    vector<int> sHalf;
    int j;
    for (j = mid + 1; j <= h; j++) {
        sHalf.push_back(arr[j]);
    }
    i = 0;
    j = 0;
    while (i < fHalf.size() && j < sHalf.size()) {
        if (fHalf[i] <= sHalf[j]) {
            arr[l++] = fHalf[i++];
        } else {
            arr[l++] = sHalf[j++];
        }
    }
    while(i < fHalf.size()) {
        arr[l++] = fHalf[i++];
    }
    while(j < sHalf.size()) {
        arr[l++] = sHalf[j++];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}
