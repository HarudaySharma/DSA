
#define SIZE 1000

class QueueArray {
    int front, rear;
    int array[SIZE];

public:
    QueueArray(){
        front = -1;
        rear = -1;
    }

    // Method to add an item to the queue.
    void enqueue(int item) {
        if(rear == SIZE)
            return;
        if(rear == -1) {
            front = 0;
        }
        array[++rear] = item;
    }

    // Method to remove an item from the queue.
    int dequeue() {
        if(front == -1)
            return -1;
        if(front == rear) {
            rear = -1;
            int ele = array[front];
            front = -1;
            return ele;

        }
        return array[front++];
    }
};
