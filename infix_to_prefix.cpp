#include <iostream>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

map<char, int> precedence = {
    {'^', 3},
    {'*', 2},
    {'/', 2},
    {'+', 1},
    {'-', 1},
};

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    stack<char> s;
	    string infix, prefix;
	    int length;
	    cin>>length; cin.ignore();
	    getline(cin, infix);
	    reverse(infix.begin(), infix.end());
	    for(auto i : infix){

            if(isalpha(i)) prefix += i;
            else if(i == '(') s.push('(');
            else if(i == ')') {
                while(s.top() != ')'){
                    prefix += s.top();
                    s.pop();
                }
                s.pop();
            }

            else{
                while(!s.empty() && precedence[i] <= precedence[s.top()]) {
                    prefix += s.top();
                    s.pop(); 
                }
                s.push(i);
            }
	    }
            
        while(!s.empty()) {
            prefix += s.top();
            s.pop();
        }
        reverse(prefix.begin(), prefix.end());
        cout<< prefix <<endl;
	}
	return 0;
}
