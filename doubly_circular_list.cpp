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
    void print();               // Traversal
    void push_back(int);        // Insertion at the end
    void push_front(int);       // Insertion at the beginning
    void push(int, int);        // Insertion at given postion
    void pop_back();            // Deletion from end   
    void pop_front();           // Deletion from beginning
    void pop(int);              // Deletion given node
};

void List::print(){
    Node *ptr = head;
    cout<<"Start --> ";
    if (head==NULL){
        cout<<"Null"<<endl;
        return;
    }
    do{
        cout<<ptr->data;
        cout<<" <--> ";
        ptr = ptr->next;
    }
    while (ptr != head);    
    cout<<endl;
}

void List::push_back(int data){
    Node *new_node = new Node();
    new_node->data = data;
    if(head == NULL){        
        new_node->next = new_node;
        new_node->prev = new_node;
        head = new_node;
    }
    else{
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
    }
}

void List::push_front(int data){
    Node *new_node = new Node();
    new_node->data = data;
    if (head == NULL){
        new_node->next = new_node;
        new_node->prev = new_node;
        head = new_node;
    }
    else{
        new_node->next = head;
        new_node->prev = head->prev;
        new_node->prev->next = new_node;
        head = new_node;
    }
    
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
        if (ptr->next == head) {
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
    else if(head->next == head){
        delete head;
        head = NULL;
    }
    else{
        Node *ptr = head->prev;
        ptr->prev->next = head;
        head->prev = ptr->prev;
        delete ptr; 
    }
}

void List::pop_front(){
    if(head == NULL) cout<<"Underflow"<<endl;
    else if(head->next == head){
        delete head;
        head = NULL;
    }
    else{
        Node *ptr = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = ptr->next;
        delete ptr;
    }
}

void List::pop(int data){
    if(head == NULL) cout<<"Underflow"<<endl;

    else if(head->data == data){
        
        if(head->next == head){
            delete head;
            head = NULL;
            return;
        }
        Node *ptr = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = ptr->next;
        delete ptr;
    }

    else{
        Node *ptr = head;
        while (ptr->data != data){
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
    }
}

int main(){
    List l;
    l.push(3);
    l.push_front(1);
    l.push(4, 3);
    l.push_back(5);
    l.push(2, 1);
    l.print();
    l.pop_back();
    l.pop_front();
    l.print();
    l.pop(2);
    l.pop(4);
    l.print();
    l.pop(3);
    l.print();
}

