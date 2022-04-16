#include <iostream>
using namespace std;

class List{
private:
    struct Node
    {
        int data;
        Node* prev;
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
        new_node->prev = NULL;
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
        new_node->prev = ptr;
        ptr->next = new_node; 
    }
}

void List::push_front(int data){
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = head;
    new_node->prev = NULL;
    if (head != NULL) head->prev = new_node;
    head = new_node;
}

void List::push(int data, int position){
    
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
    new_node->prev = ptr;
    ptr->next->prev = new_node;
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
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        delete ptr; 
    }
}

void List::pop_front(){
    if(head == NULL) cout<<"Underflow"<<endl;
    else{
        Node *ptr = head;
        head = ptr->next;
        head->prev = NULL;
        delete ptr;
    }
}

void List::pop(int data){
    if(head == NULL) cout<<"Underflow"<<endl;

    else if(head->data == data){
        Node *ptr = head;
        head = ptr->next;
        head->prev = NULL;
        delete ptr;
    }

    else{
        Node *ptr = head;
        while (ptr->data != data){
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next;
        if (ptr->next != NULL) ptr->next->prev = ptr->prev;
        delete ptr;
    }
}

int main(){
    List l;
    l.push_back(1);
    l.push_front(0);
    l.push(3, 3);
    l.print();
}

