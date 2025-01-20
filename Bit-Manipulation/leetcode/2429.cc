#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int minimizeXor(int num1, int num2) {
        int reqSetBits = countSetBits(num2);

        int x = num1;
        int xSetBits = countSetBits(x);

        if(xSetBits == reqSetBits) {
            return x;
        }
        else if(xSetBits < reqSetBits) {
            addSetBitsFromLSB(x, reqSetBits - xSetBits);
        } else {
            removeSetBitsFromMSB(x, xSetBits - reqSetBits);
        }

        return x;
    }

private:

    void removeSetBitsFromMSB(int &num, int numOfBits) {
        if (num == 0 || numOfBits <= 0) {
            return;  // Nothing to remove
        }

        while(numOfBits) {
            int x = num;
            int places = 0;

            while((x & 1) == 0) {
                x >>= 1;
                places += 1;
            }
            int mask = 1 << places;
            num &= (~mask);  // Clear the bit

            numOfBits--;
        }
    }

    void addSetBitsFromLSB(int &num, int numOfBits) {
        // how to add bits from lsb?
        while(numOfBits) {
            int x = num;
            int places = 0;

            while(x & 1) {
                x >>= 1;
                places += 1;
            }
            int mask = 1 << places;
            num |= (mask);

            numOfBits--;
        }

        return;
    }

    void printBinaryForm(int num) {
        if(!num) {
            return;
        }
        printBinaryForm(num / 2);
        cout << num % 2;
    }

    int countSetBits(int num) {
        int bits = 0;
        while(num) {
            if(num & 1) {
                bits++;
            }
            num >>= 1;
        }

        return bits;
    }
};


