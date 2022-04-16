#include<iostream>

using namespace std;

const int size = 10;

class Stack{
    int top;

    public:
    int arr[size];

    Stack(){
        top = -1;
    }

    void push(int);
    void pop();
    int peek();
    bool isFull();
    bool isEmpty();
};

void Stack::push(int element){
    if (top >= size - 1){
        cout<<"Stack Overflaw"<<endl;
        return;
    }
    arr[++top] = element;
    cout<<element<<" pushed into Stack"<<endl;
}

void Stack::pop(){
    if (top <= -1){
        cout<<"Stack Underflaw"<<endl;
        return;
    }
    cout<<arr[top--]<<" poped from Stack"<<endl;    
}

int  Stack::peek() { return arr[top]; }

bool Stack::isFull() { return top == size-1; }

bool Stack::isEmpty() { return top == -1; }

int main(){
    Stack s;
    cout<<"Stack is "<<(s.isEmpty() ? "Empty" : "not Empty")<<endl;
    cout<<"Stack is "<<(s.isFull() ? "Full" : "not Full")<<endl;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"top elememt of Stack is: "<<s.peek()<<endl;
    s.push(5);
    cout<<"top elememt of Stack is: "<<s.peek()<<endl;
    s.pop();
    cout<<"top elememt of Stack is: "<<s.peek()<<endl;
    while(!s.isEmpty()){
        s.pop();
    }
    cout<<"Stack is "<<(s.isEmpty() ? "Empty" : "not Empty")<<endl;
    s.pop();
    return 0;
}