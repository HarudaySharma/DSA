#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class QueueArray
{
    public:
        int SIZE;
        int front;
        int rear;
        int array[100];
        QueueArray()
        {
            SIZE=100;front=-1;rear=-1;
        }

        // Method add an item to the queue.
        void enqueue(int item)
        {
            if (rear == SIZE)   // Queue is full
                return;
            if(front == -1 && rear == -1)
                front = rear = 0;
            else
                rear++;
            array[rear] = item;
        }

        // Method to remove an item from queue.
        int dequeue()
        {
            if (front > rear)
                return -1;
            int item = array[front];
            front++;
            return item;
        }
};

class Stack {
    public:
        void push(QueueArray* qa1, QueueArray* qa2, int item) {
            qa1->enqueue(item);
        }

        int pop(QueueArray* qa1, QueueArray* qa2) {
            while(qa1->front != qa1->rear) {
                qa2->enqueue(qa1->dequeue());
            }
            int item = qa1->dequeue();
            qa1->front = qa1->rear = -1;
            while(qa2->front != qa2->rear) {
                qa1->enqueue(qa2->dequeue());
            }
            qa1->enqueue(qa2->dequeue());
            qa2->front = qa2->rear = -1; 
            return  item;
        }
};
