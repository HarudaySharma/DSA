#include "iostream"
using namespace std;

class QueueNode {
public:
    int data;
    QueueNode* next;

    QueueNode(int data) {
        this->data = data;
        next = nullptr;
    }
};

class QueueLinkedList {
public:
    QueueNode* front;
    QueueNode* rear;

    QueueLinkedList() {
        front = nullptr;
        rear = nullptr;
    }

    void EnQueue(int data) {
        QueueNode *newNode = new QueueNode(data);
        if(!front) {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int DeQueue() {
        if(front == nullptr) {
            return -1;
        }
        int data = front->data;
        if(front == rear){ 
            delete front;
            front = rear = nullptr;
            return data;
        }
        QueueNode *temp = front;
        front = front->next;
        delete temp;
        return data;
    }
};
int main() {
    int t, n, q1, q2;
    cin >> t;
    while (t--) {
        QueueLinkedList ob1;
        cin >> n;
        while (n--) {
            cin >> q1;
            if (q1 == 1) {
                cin >> q2;
                ob1.EnQueue(q2);
            } else {
                cout << ob1.DeQueue() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
