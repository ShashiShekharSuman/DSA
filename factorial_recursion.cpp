#include <iostream>

using namespace std;

typedef long long ll;

ll factorial(int n){

    if (n == 0){
        return 1;
    }
    else{
        return n * factorial(n - 1);
    }
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n > -1){
        cout << "Factorial of " << n << " = " << factorial(n);
    }
    else{
        cout<<"Factorial does not exist for negative integer";
    }
    return 0;
}