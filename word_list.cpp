#include <iostream>
using namespace std;

class List{
private:
    struct Node
    {
        string word;
        Node *next;

        
    };

    Node *head;
    
public:
    List(){
        head = NULL;
    }
    void print();             //Traversal
    int count();              //Count
    void push(string);        //Insertion
    void pop(string);         //Deletion
    void reverse();           //Reversal
    void sort();              //Sort
    List operator +(List &);  //Concatination
};

void List::print(){
    cout<<"Start";
    Node *ptr = head;
    
    while (ptr != NULL)
    {
        cout<<" --> "<<ptr->word;
        ptr = ptr->next;
    }
    cout<<endl;
}

int List::count(){
    if(head == NULL) return 0;
    else {
        int count = 0;
        Node* ptr = head;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        return count;
    }
}

void List::push(string word){
    if(head == NULL){
        Node *new_node = new Node();
        new_node->word = word;
        new_node->next = NULL;
        head = new_node;
    }
    else{
        Node *ptr = head;
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        Node *new_node = new Node();
        new_node->word = word;
        new_node->next = NULL;
        ptr->next = new_node; 
    }
}

void List::pop(string word){
    if(head == NULL) cout<<"Underflow";

    else if(head->word == word){
        Node *ptr = head;
        head = ptr->next;
        delete ptr;
    }

    else{
        Node *ptr = head, *ptr1;
        while (ptr->word != word){
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = ptr->next;
        delete ptr;
    }
}

void List::reverse(){
    if (head == NULL || head->next == NULL) return;

    Node *ptr = head->next, *ptr1 = head, *temp;
    while(ptr != NULL){
        temp = ptr;
        ptr = ptr->next;
        temp->next = head;
        head = temp;
    }
    ptr1->next = NULL;
}

void List::sort(){
    for(Node *ptr_i = head; ptr_i->next != NULL; ptr_i = ptr_i->next)
        for(Node *ptr_j = ptr_i->next; ptr_j != NULL; ptr_j = ptr_j->next){
            if(ptr_i->word > ptr_j->word){
                string temp = ptr_i->word;
                ptr_i->word = ptr_j->word;
                ptr_j->word = temp;
            }
        }
}

List List::operator +(List &list){
    if (head == NULL) return list;
    List final_list;
    final_list.head = head;
    if (list.head == NULL) return final_list;
    Node *ptr = final_list.head;
    while(ptr->next != NULL) ptr = ptr->next;
    ptr->next = list.head;
    return final_list;
}

int main(){
    List words;
    words.push("abc");
    words.push("pqr");
    words.push("xyz");
    words.print();
    cout<<"Number of words = "<<words.count()<<"\n\n";
    List new_words;
    new_words.push("123");
    new_words.push("789");
    new_words.print();
    cout<<"Number of words = "<<new_words.count()<<"\n\n";
    List word_list = words + new_words;
    word_list.print();
    cout<<"Number of words = "<<word_list.count()<<"\n\n";
    word_list.pop("789");
    word_list.print();
    cout<<"Number of words = "<<word_list.count()<<"\n\n";
    word_list.sort();
    word_list.print();
    cout<<endl;
    word_list.reverse();
    word_list.print();
}

