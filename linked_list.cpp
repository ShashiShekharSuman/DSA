#include <iostream>
using namespace std;

class List{
private:
    struct Node
    {
        int data;
        Node *next;
    };

    Node *head;  
    
public:
    List(){
        head = NULL;
    }
    void print();
    void push_back(int);
    void push_front(int);
    void push(int, int);
    void pop_back();
    void pop_front();
    void pop(int);
};

void List::print(){
    Node *ptr = head;
    cout<<"Start";
    while (ptr != NULL)
    {
        cout<<" --> "<<ptr->data;
        ptr = ptr->next;
    }
    cout<<endl;
}

void List::push_back(int data){
    if(head == NULL){
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = NULL;
        head = new_node;
    }
    else{
        Node *ptr = head;
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = NULL;
        ptr->next = new_node; 
    }
}

void List::push_front(int data){
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void List::push(int data, int position=0){
    if (position == 0){
        push_front(data);
        return;
    }
    if(head == NULL){
        cout<<"Position does not exist"<<endl;
        return;
    }
    Node *ptr = head;
    while(ptr->data != position){
        if (ptr->next == NULL) {
            cout<<"Position does not exist"<<endl;
            return;
        }
        ptr = ptr->next;
    }
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = ptr->next;
    ptr->next = new_node;
}

void List::pop_back(){
    if(head == NULL) cout<<"Underflow"<<endl;
    else if(head->next == NULL){
        delete head->next;
        head = NULL;
    }
    else{
        Node *ptr = head;
        while (ptr->next->next != NULL){
            ptr = ptr->next;
        }
        delete ptr->next;
        ptr->next = NULL; 
    }
}

void List::pop_front(){
    if(head == NULL) cout<<"Underflow"<<endl;
    else{
        Node *ptr = head;
        head = ptr->next;
        delete ptr;
    }
}

void List::pop(int data){
    if(head == NULL) cout<<"Underflow";

    else if(head->data == data){
        Node *ptr = head;
        head = ptr->next;
        delete ptr;
    }

    else{
        Node *ptr = head, *ptr1;
        while (ptr->data != data){
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = ptr->next;
        delete ptr;
    }
}

int main(){
    List l;
    // l.push(1);
    l.push(2, 2);
    l.print();
}

