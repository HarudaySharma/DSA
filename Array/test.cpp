#include "iostream"

void func(int a[5])
{
    int i;
    for(i = 1; i < 3; i++)
    {
        a[i] = a[i-1] + a[i+1];
        if(a[i]%2 == 0)
            a[i] /= 2;
    }
}

int main (int argc, char *argv[]) {

    int arr[] = {5, 65, 45, 2, 25};
    func(arr);
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}
