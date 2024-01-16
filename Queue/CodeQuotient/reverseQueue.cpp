#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
using namespace std;

class Queue{
    int *queue;
    int front;
    int rear;
    int size;
    public:
    Queue(int size){
        this->size = size;
        queue = new int[size];
        front = 0;
        rear = 0;
    }
    void enQueue(int data);
    int deQueue();
    bool isEmpty();
};
void Queue::enQueue(int data){
    if(rear == size){
        cout<<"Overflow\n";
        return;
    }
    queue[rear++] = data;
}
int Queue::deQueue(){
    if(front == rear){
        return -1;
    }
    return queue[front++];
}
bool Queue::isEmpty(){
    return front == rear;
}

void reverseQueue(Queue *queue){
    int data = queue->deQueue();
    if(data == -1)
        return;
    reverseQueue(queue);
    queue->enQueue(data);
    return;
        
}
