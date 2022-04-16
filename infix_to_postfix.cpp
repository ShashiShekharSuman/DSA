#include <iostream>
#include <stack>
#include <map>
using namespace std;

int precedence(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int main() {
	// your code goes here
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int length;
	    cin>>length;
    	string infix_expression, postfix_expression;
        getline(cin, infix_expression);
        stack<char> stack;
        for(auto i : infix_expression){
            if(isalpha(i))
                postfix_expression += i;
     
            else if(i == '(')
                stack.push(i);
     
            else if(i == ')') {
                while(stack.top() != '(')
                {
                    postfix_expression += stack.top();
                    stack.pop();
                }
                stack.pop();
            }
    
            else{
                while(!stack.empty() && precedence(i) <= precedence(stack.top())) {
                    postfix_expression += stack.top();
                    stack.pop(); 
                }
                stack.push(i);
            }  
        }
    
        while(!stack.empty()) {
            postfix_expression += stack.top();
            stack.pop();
        }
    
        cout << postfix_expression << endl;
    } 
	return 0;
}
