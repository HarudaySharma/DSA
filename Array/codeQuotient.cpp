#include "iostream"
#include "cstdlib"


template<class T>
class Array {
public:

    static void reverse(int *arr, int i, int j){

        while(i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j--;
        }
    }

    static T smax(T *arr, int n){
        int max = arr[0];
        int smax = arr[0];

        for (int i = 0; i < n; i++) {
            if(arr[i] > max) {
                smax = max;
                max = arr[i];
            }
            else if (arr[i] < max && arr[i] > smax) {
                smax = arr[i];
            }

        }
        return smax == max ? 0 : smax; 
    }
    
    static T maxFreq(T *arr, int n){
        
        T max = arr[0];
        for (int i = 1; i < n; i++) {
            if (max < arr[i])
                max = arr[i];
        }

        T *freqArr = new T[max + 1]; 
        for (int i = 0; i < n; i++) {
            freqArr[arr[i]] = 0;
        }

        for (int i = 0; i < n; i++) {
            freqArr[arr[i]] += 1;
        }

        T mostFreq[] = {arr[0], freqArr[arr[0]]};
        for (int i = 1; i < n; i++) {
            if(freqArr[arr[i]] > mostFreq[1]) {
                mostFreq[0] = arr[i];
                mostFreq[1] = freqArr[arr[i]];
            }
            else if (freqArr[arr[i]] == mostFreq[1] && arr[i] < mostFreq[0]) {
              mostFreq[0] = arr[i];
              mostFreq[1] = freqArr[arr[i]];
            }
        }
        delete []freqArr;
        return mostFreq[0];
    }

    static void countAndPrint(int *arr, int n) {

        int pos = 0, neg = 0;
        int even = 0, odd = 0;

        for (int i = 0; i < n; i++) {
            arr[i] < 0 ? neg++ : pos++;
            arr[i] % 2 == 0 ? even++ : odd++;
        }
        std::cout << pos << "\n" << neg << "\n";
        std::cout << even << "\n" << odd << "\n";
    }

    static bool areArraysEqual(int *arr1, int* arr2, int n, int offset) {

        int *hash = new int[offset];

        for (int i = 0; i < n; i++) {
            hash[std::abs(arr1[i])] = 0;
        }

        for(int i = 0; i < n; i++) {
            hash[std::abs(arr1[i])] += 1;
        }

        for(int i = 0; i < n; i++) {
            hash[std::abs(arr2[i])] -= 1;
        }

        for(int i = 0; i < n; i++) {
            if(hash[std::abs(arr1[i])] != 0)
                return false;
        }
        delete []hash;
        return true;

    }

    static void moveElements(int *arr, int n) {
        /*
         * using 2 pointers

        int i = 0;
        int j = n - 1;

        while(i < j) {
            while(arr[i] >= 0)
                i++;
            while(arr[j] < 0)
                j--;

            if(i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

        }*/

        int negs = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] < 0) negs++; 
        }
        while(negs) {
            for(int i = 0; i < n; i++) {
                if(arr[i] < 0){
                    reverse(arr, i + 1, n);
                    reverse(arr, i, n);
                    negs--;
                    break;
                }
            }
        }

        /*
         * simple travering and swapping

         for(int i = 0; i < n; i++) { 
            if(arr[i] >= 0) continue;
            for(int j = i + 1; j < n; j++){
                if(arr[j] >= 0) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    break;
                }
            }
        }*/    

        /*
         * simple reverse of the left to be traversed part

        int i = 0;
        int j = n - 1;
        while(i < j) {
            while(arr[i] >= 0) i++;
            while(arr[j] < 0) j--;
            Array::reverse(arr, i, j);

        }*/

    }


};

int main (int argc, char *argv[]) {
    int *arr = new int[argc - 1];
    for (int i = 1; i < argc; i++) {
        int k = 1;
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if(j == 0) {
                arr[i - 1] = (int) argv[i][j] - '0';
                continue;
            }
           k *= 10; 
            arr[i - 1] *=  k;
            arr[i - 1] += ((int) argv[i][j] - '0'); 
        }
    }
    std::cout << Array<int>::maxFreq(arr, argc - 1) << "\n";
    return 0;
}
