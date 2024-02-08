#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>

int left(int pos) {
    return 2 * pos + 1;
}

int right(int pos) {
    return 2 * pos + 2;
}

/* approach : 
 * go to the leftmost node of the current node 
 * print that leftmost node and then got to the right of that leftmost node
 * repeat the same operation 
 */
void inOrderTraversal(int * arr, int n) {
    if(n == 0) {
        return;
    }
    int curr = 0;
    std::stack<int>s;
    while(curr < n || !s.empty()) {
        // for reaching the leftmost node
        while(curr < n) {
            s.push(curr);
            curr = left(curr);
        }
        
        if(!s.empty()) {
            curr = s.top();
            s.pop();
            std::cout << arr[curr];
            curr = right(curr);
        }
        

    }
}

int main (int argc, char *argv[]) {
    int arr[] = {1,2,3,4,5,6,7};
    inOrderTraversal(arr, 7);
    return 0;
}
