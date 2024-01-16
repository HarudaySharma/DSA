#include<iostream>
using namespace std;
#define SIZE 4

//Program when front and rear starts from -1
class QueueArray{
  int front,rear;
  int *queue;
  public:
    QueueArray(){
      queue=new int[SIZE];
      front = -1;
      rear = -1;
    }
  	void enQueue(int data);
  	int deQueue();
};
void QueueArray::enQueue(int data) {
    if(front == -1) {
        if(rear + 1 == SIZE)
            return;
    }
    if((rear + 1) % SIZE == front) {
        return ;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = data;
}

int QueueArray::deQueue() {
    if(front == rear) {
        return -1;
    }
    front = (front + 1) % SIZE;
    return queue[front];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        QueueArray *queue = new QueueArray();
        while(n--){
            int choice ;
            cin>>choice;
            if(choice == 1){
                int data;
                cin>>data;
                queue->enQueue(data);
            }else if(choice == 2){
                cout<<queue->deQueue()<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}
