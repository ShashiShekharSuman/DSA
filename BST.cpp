#include <iostream>

using namespace std;

class Bst{
    struct Node {  
        int data;  
        Node *left;  
        Node *right; 
        
        Node(int data){
            this->data = data;
            this->left = this->right = NULL;
        }
    };

    Node *root;
    
    void inOrder(Node*);
    Node* insertion(Node*, int);
    Node* deletion(Node*, int);
    Node* min_node(Node*);

    public:

    Bst();                          // Creation
    void inOrder_Traversal();       // Traversal
    void push(int);                 // Insertion
    void pop(int);                  // Deletion
};  

Bst::Bst(){
    this->root = NULL;
}

void Bst::inOrder_Traversal(){
    cout<<"Inorder Traversal: ";
    inOrder(root);
    cout<<endl;
}

void Bst::push(int data){
    root = insertion(root, data);
}

void Bst::pop(int data){
    root = deletion(root, data);
}

void Bst::inOrder(Node* node) {
    if (node == NULL)  return;  
    inOrder(node->left);  
    cout<< node->data << "   ";  
    inOrder(node->right);
}

Bst::Node* Bst::insertion(Node* node, int data){
    if (node == NULL)  return new Node(data);  
    if (data < node->data) node->left = insertion(node->left, data);  
    else node->right = insertion(node->right, data);  
    return node;  
}

Bst::Node* Bst::deletion(Node* node, int data){
    if (node == NULL) return node;
    if (data < node->data) node->left = deletion(node->left, data);
    else if (data > node->data) node->right = deletion(node->right, data);
    else {
        if (node->left==NULL and node->right==NULL) return NULL;
        else if (node->left == NULL) {
            Node* tempNode = node->right;
            delete node;
            return tempNode;
        }
        else if (node->right == NULL) {
            Node* tempNode = node->left;
            delete node;
            return tempNode;
        }
        Node* tempNode = min_node(node->right);
        node->data = tempNode->data;
        node->right = deletion(node->right, node->data);
    }
    return node;
}

Bst::Node* Bst::min_node(Node* node){
    Node* minNode = node;
    while (minNode && minNode->left != NULL) minNode = minNode->left;
    return minNode;
}

int main(){
    Bst bst;
    bst.push(70);
    bst.push(30);
    bst.push(20);
    bst.push(10);
    bst.push(80);
    bst.inOrder_Traversal();
    bst.pop(20);
    bst.inOrder_Traversal();
    bst.pop(30);
    bst.inOrder_Traversal();
    bst.push(50);
    bst.inOrder_Traversal();
    bst.pop(50);
    bst.inOrder_Traversal();
    return 0;
}