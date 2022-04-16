#include<iostream>

using namespace std;

class Queue{
    int front, rear;
    unsigned capacity;
    int *arr;

    public:

    Queue(int n){
        this->front = -1;
        this->rear = -1;
        this->capacity = n;
        this->arr = new int[this->capacity*1];
    }

    void enqueue(int);
    void dequeue();
    int peek();
    bool isFull();
    bool isEmpty();
};

void Queue::enqueue(int element){
    if (isFull()){
        cout<<"Queue Overflaw"<<endl;
        return;
    }
    arr[++rear] = element;
    if (front < 0) front++;
    cout<<element<<" enqueued into Queue"<<endl;
}

void Queue::dequeue(){
    if (isEmpty()){
        cout<<"Queue Underflaw"<<endl;
        return;
    }
    cout<<arr[front++]<<" dequeued from Queue"<<endl; 
    if (front > rear) front = rear = -1;
}

int  Queue::peek() { return arr[front]; }

bool Queue::isFull() { return rear == capacity-1; }

bool Queue::isEmpty() { return front == -1; }

int main(){
    Queue q(10);
    cout<<"Queue is "<<(q.isEmpty() ? "Empty" : "not Empty")<<endl;
    cout<<"Queue is "<<(q.isFull() ? "Full" : "not Full")<<endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<"front elememt of Queue is: "<<q.peek()<<endl;
    q.enqueue(5);
    cout<<"front elememt of Queue is: "<<q.peek()<<endl;
    q.dequeue();
    cout<<"front elememt of Queue is: "<<q.peek()<<endl;
    while(!q.isEmpty()){
        q.dequeue();
    }
    cout<<"Queue is "<<(q.isEmpty() ? "Empty" : "not Empty")<<endl;
    q.dequeue();
    return 0;
}