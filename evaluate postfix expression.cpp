//Program to evaluate a post-fix expression entered by the user.
#include<iostream>
#include<math.h>

using namespace std;


class Stack{
    int top;
    int size;
    float *arr;
    public:
    

    Stack(int length){
        this->size = length;
        this->arr = new float[this->size];
        this->top = -1;
    }

    void push(float);
    void pop();
    float peek();
};

void Stack::push(float element){
    if (top >= size - 1){
        cout<<"Stack Overflaw"<<endl;
        return;
    }
    arr[++top] = element;
}

void Stack::pop(){
    if (top == -1){
        cout<<"Stack Underflaw"<<endl;
        return;
    }
    top--;   
}

float  Stack::peek() { return arr[top]; }

int main(){
    cout<<"Entre posfix expression: ";
    string expression;
    getline(cin, expression);
    Stack stack(expression.length());
    bool flag = false;
    for(auto i : expression){
        if(i == ' ') {
            flag = false;
            continue;
        }
        else if(isdigit(i)){
            if (flag){
                float temp = stack.peek();
                stack.pop();
                stack.push( 10 * temp + i - '0');
            }
            else stack.push(i - '0');
            flag = true;
        }
        else{
            float b = stack.peek();
            stack.pop();
            float a = stack.peek();
            stack.pop();
            switch (i)
            {
            case '+': stack.push(a + b); break;
            case '-': stack.push(a - b); break;
            case '*': stack.push(a * b); break;
            case '/': stack.push(a / b); break;
            case '^': stack.push(pow(a, b)); break;
            default: cout<<"undefined operator "<<i<<endl;
            }
        }
    }
    cout << expression << " = " << stack.peek();     
}