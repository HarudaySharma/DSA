
class Node
{
    public:
        int data; // data item
        Node *next; // next link in list
        Node(int dd) // constructor
        { 
            data = dd;
            next = nullptr;
        }
};
// ***********************************************************************************************
class LinkStack{
    private:
        Node *first; // ref to first item on list
    public:
        LinkStack();
        bool isEmpty();
        void push(int);
        int pop();
};

LinkStack::LinkStack() {
    first = nullptr;
}

void LinkStack::push(int data) {
    Node* newNode = new Node(data);
    newNode->next = first;
    first = newNode;
}

int LinkStack::pop() {
    if(this->isEmpty()) 
        return -1;

    int data = first->data;
    Node* temp  = first;
    first = first->next;
    delete temp;
    
    return data;
}


bool LinkStack::isEmpty() {
    return !first;
}
