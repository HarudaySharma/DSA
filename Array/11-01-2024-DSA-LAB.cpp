#include "iostream"
#include <ostream>
#include <unordered_set>

class Solution {
public:
    static void  nonPairDolls(int* arr, int n) {
        int max = arr[0];
        for (int i = 1; i < n; i++) 
            if(max < arr[i]) max = arr[i];

        int *freq = new int[max + 1];
        for(int i = 0; i < max + 1; i++) {
            freq[i] = 0;
        }
        for(int i = 0; i < n; i++) {
            freq[arr[i]] += 1;
        }
        std::cout << "Non Pair Dolls \n";
        for(int i = 0; i < max + 1; i++) {
            if(freq[i] % 2 != 0)
                std::cout << i << std::endl;
        }
        delete []freq;

    }
    static int friendshipSafe(int* arr, int n) {
        std::unordered_set<int> *days = new std::unordered_set<int>;
        for(int i = 0; i < n; i++)
            days->insert(arr[i]);
        int answer = days->size();
        delete days;
        return answer;
    }

    static int minOperationsToMakeElementsEqual(int *arr, int n){
        // find the element having max freq.
        int max = arr[0];
        for (int i = 1; i < n; i++) 
            if(max < arr[i]) max = arr[i];

        int *freq = new int[max + 1];
        for(int i = 0; i < n; i++) {
            freq[arr[i]] = 0;
        }
        for(int i = 0; i < n; i++) {
            freq[arr[i]] += 1;
        }
        int maxFreq = freq[arr[0]];
        for (int i = 1; i < n; i++) 
            if(maxFreq < freq[arr[i]]) maxFreq = freq[arr[i]];

        return n - maxFreq;
    }

};
int main (int argc, char *argv[]) {
    int t;
      //  std::cout << "Number of test cases ? " ;
    std::cin >> t;
    //std::cout << "***MENU***" << "\n";
    //std::cout << "1. Find Non-Pair Dolls" << "\n";
    //std::cout << "2. Friendships not lost " << "\n";
    //std::cout << "3. Minimum operations to make element equal" << "\n";
    //std::cout << "Select the Operation: ";
    int choice;
    std::cin >> choice;
    //std::cout << "\n";
    //std::cout << std::endl;
    while (t--) {
        int n;
        //std::cout << "Enter size of array "  ;
        std::cin >> n;
        //std::cout << std::endl;

        //std::cout << "Enter elements" << "\n"  ;

        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i]; 
        }


        switch (choice) {
            case 1: 
                Solution::nonPairDolls(arr, n);
            break;
            case 2: 
            std::cout << "Friendships not lost:" << Solution::friendshipSafe(arr, n) << "\n";
            break;
            case 3: 
            std::cout << "minimum Operations: " << Solution::minOperationsToMakeElementsEqual(arr, n) << "\n";
            break;
        }

        delete [] arr;
        
    }            

    return 0;
}

