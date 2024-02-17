#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

#define SIZE 14

class CicularQueue {
    private:
        int arr[SIZE];
        int front;
        int rear;
    public: 
        CicularQueue() :
            front(-1), rear(-1) {}

        void push(int data) {
            if(front == -1) {
                front = 0;
                arr[++rear] = data;
                return;
            }
            rear = ( rear + 1 ) % SIZE;
            if(rear == front) {
                return;
            }
            arr[rear] = data;
        }

        int pop() {
            if(front == -1 || front > rear)
                return -1;
            int data = arr[front];
            front = (front + 1) % SIZE;
            return data;
        }
};
